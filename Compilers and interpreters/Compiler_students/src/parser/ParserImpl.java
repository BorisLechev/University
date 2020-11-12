/*
MIT License

Copyright (c) 2018 Computing and Engineering Department, Technical University of Varna

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

package parser;

import bg.tu_varna.kst_sit.ci_ep.ast.*;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.ArrayInitNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.AssignableNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.CharacterLiteralNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.StringLiteralNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.*;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.additive_operators.AdditionNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.additive_operators.SubtractionNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.logical_operators.AndNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.logical_operators.OrNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.multiplicative_operators.DivisionNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.multiplicative_operators.ModNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.multiplicative_operators.MultiplicationNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.binary_operators.relational_operators.*;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.unary_operators.MinusNode;
import bg.tu_varna.kst_sit.ci_ep.ast.assignable.expression.operators.unary_operators.NotNode;
import bg.tu_varna.kst_sit.ci_ep.ast.global_definition.FunctionDefinitionNode;
import bg.tu_varna.kst_sit.ci_ep.ast.global_definition.GlobalDefinitionNode;
import bg.tu_varna.kst_sit.ci_ep.ast.global_definition.VariableDefinitionNode;
import bg.tu_varna.kst_sit.ci_ep.ast.statement.*;
import bg.tu_varna.kst_sit.ci_ep.ast.type.PrimitiveTypeNode;
import bg.tu_varna.kst_sit.ci_ep.ast.type.TypeNode;
import bg.tu_varna.kst_sit.ci_ep.ast.type.VoidTypeNode;
import bg.tu_varna.kst_sit.ci_ep.exceptions.SyntaxException;
import bg.tu_varna.kst_sit.ci_ep.lexer.Lexer;
import bg.tu_varna.kst_sit.ci_ep.lexer.token.Token;
import bg.tu_varna.kst_sit.ci_ep.parser.Parser;
import bg.tu_varna.kst_sit.ci_ep.source.SourceImpl;
import bg.tu_varna.kst_sit.ci_ep.utils.CompilerTestHelper;
import lexer.LexerImpl;
import token.TokenType;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ParserImpl extends Parser<TokenType, AST> {

    public ParserImpl(Lexer<TokenType> lexer) {
        super(lexer);
    }

    private void accept(TokenType tokenType) {
        if (currentToken.getTokenType() != tokenType) { // dali tokena na poziciata v izrechenieto
            throw new SyntaxException("Token doesn't match! Expected " +
                    tokenType.value + ", Got " + currentToken.getTokenType().value, currentToken);
        }
        currentToken = lexer.nextToken();
    }

    @Override
    public AST entryRule() {
        accept(TokenType.PROGRAM);
        accept(TokenType.LBRACKET);
        programBody();
        accept(TokenType.RBRACKET); // terminalen simvol
        return currentNode;
    }

    void programBody() {
        List<GlobalDefinitionNode> globalDefinitions = new ArrayList<>();
        while(
                TokenType.isPrimitiveType(currentToken.getTokenType()) ||
                        (currentToken.getTokenType() == TokenType.IDENTIFIER && !currentToken.getText().equals("main"))
                ) {
            if (currentToken.getTokenType() == TokenType.IDENTIFIER) {
                functionDefinition();
            } else {
                variableDefinition();
                accept(TokenType.SEMICOLON);
            }
            globalDefinitions.add((GlobalDefinitionNode) currentNode);
        }
        mainFunction();
        globalDefinitions.add((GlobalDefinitionNode) currentNode);
        currentNode = new ProgramBodyNode(null, globalDefinitions);
    }

    void functionDefinition() {
        Token token = currentToken;
        accept(TokenType.IDENTIFIER); //IDENTIFIER terminalen symbol glavni bukvi /* ToDo handle symbol */
        accept(TokenType.LPAREN); //IDENTIFIER terminalen symbol glavni bukvi/* ToDo handle symbol */


        FormalParameterNode formalParameters = null;
        if (TokenType.isPrimitiveType(currentToken.getTokenType())) {
            formalParameters();/* ToDo SyntaxAnalysis  - handle symbol - ot Kolesnichenko */
            formalParameters = (FormalParameterNode) currentNode;
        }

        accept(TokenType.RPAREN);/* ToDo handle symbol */
        accept(TokenType.ARROW);/* ToDo handle symbol */

        TypeNode typeNode;
        if (currentToken.getTokenType() == TokenType.VOID) {
            typeNode = new VoidTypeNode(currentToken);
            accept(TokenType.VOID);/* ToDo handle symbol */
        } else {
            type();/* ToDo handle symbol */
            typeNode = (TypeNode) currentNode;
        }
        block();/* ToDo handle symbol */
        BlockNode blockNode = (BlockNode)currentNode;
        currentNode = new FunctionDefinitionNode(token, formalParameters, typeNode, blockNode);
    }

    void functionCall() {
        accept(TokenType.AT);/* ToDo handle symbol */

        Token token = currentToken;

        accept(TokenType.IDENTIFIER);/* ToDo handle symbol */
        accept(TokenType.LPAREN); /* ToDo handle symbol */
        ActualParameterNode actualParameters = null;
        if (TokenType.isLiteralTerminal(currentToken.getTokenType())) {
            actualParameters();/* ToDo handle symbol */
            actualParameters = (ActualParameterNode) currentNode;
        }
        accept(TokenType.RPAREN);/* ToDo handle symbol */
        currentNode = new FunctionCall(token, actualParameters);
    }

    void type() {
        Token token = currentToken;
        boolean isArray = false;
        if (TokenType.isPrimitiveType(currentToken.getTokenType())) {
            accept(currentToken.getTokenType());
            if (currentToken.getTokenType() == TokenType.LSQUARE) {
                isArray = true;
                accept(TokenType.LSQUARE);/* ToDo handle symbol */  //a[] ima masiva
                accept(TokenType.RSQUARE);/* ToDo handle symbol */
            }
        } else {
            throw new SyntaxException("Expected return type. Got " + currentToken.getTokenType().value, currentToken);
        }
        currentNode = new PrimitiveTypeNode(token, isArray);
    }

    void formalParameters() {
        List<TypedVariableNode> formalParameters = new ArrayList<>();
        type(); /* ToDo handle symbol */
        formalParameters.add(new TypedVariableNode(null, (TypeNode) currentNode, new VariableNode(currentToken, null)));
        accept(TokenType.IDENTIFIER);/* ToDo handle symbol */
        while (currentToken.getTokenType() == TokenType.COMMA) { //*
            accept(TokenType.COMMA);/* ToDo handle symbol */
            type(); /* ToDo handle symbol */
            formalParameters.add(new TypedVariableNode(null, (TypeNode) currentNode, new VariableNode(currentToken, null)));
            accept(TokenType.IDENTIFIER);/* ToDo handle symbol */
        }
        currentNode = new FormalParameterNode(null, formalParameters);
    }

    void actualParameters() {
        List<AssignableNode> params = new ArrayList<>();
        assignable();/* ToDo handle symbol */
        params.add((AssignableNode) currentNode);
        while(currentToken.getTokenType() == TokenType.COMMA) {
            accept(TokenType.COMMA);/* ToDo handle symbol */
            assignable();/* ToDo handle symbol */
            params.add((AssignableNode) currentNode);
        }
        currentNode = new ActualParameterNode(null, params);
    }

    void variableDefinition() {
        type();/* ToDo handle symbol */
        TypeNode type = (TypeNode)currentNode;
        assignment();/* ToDo handle symbol */
        currentNode = new VariableDefinitionNode(null, type, (AssignmentNode) currentNode);
    }

    void assignment() {
        variable();/* ToDo handle symbol */
        VariableNode variable = (VariableNode) currentNode;
        Token token = currentToken;

//        assignment(); /* ToDo handle symbol ot men dobaveno */
        accept(TokenType.BECOMES);/* ToDo handle symbol */
        if (TokenType.isPrimitiveType(currentToken.getTokenType())) {
            arrayInitialization();
        } else if (TokenType.CHAR_LITERAL == currentToken.getTokenType()) {
            characterLiteral();
        } else if (TokenType.STRING_LITERAL == currentToken.getTokenType()) {
            stringLiteral();
        } else {
            expression();
        }
        AssignableNode assignable = (AssignableNode) currentNode;
        currentNode = new AssignmentNode(token, variable, assignable);
    }

    void arrayInitialization() {
        Token token = currentToken;
        ExpressionNode expression = null;
        if (TokenType.isPrimitiveType(currentToken.getTokenType())) {
            //            arrayInitialization(); Yoan ???????


            accept(currentToken.getTokenType());/* ToDo handle symbol currentToken (currentToken.getTokenType()) */
            accept(TokenType.LSQUARE);/* ToDo handle symbol */
            expression();/* ToDo handle symbol */
            expression = (ExpressionNode) currentNode;
            accept(TokenType.RSQUARE);/* ToDo handle symbol */
        } else {
            System.out.println("Expected array initialization. Got " + currentToken.getTokenType());
        }
        currentNode = new ArrayInitNode(token, expression);
    }

    void block() {
        List<Statement> statements = new ArrayList<>();
        accept(TokenType.LBRACKET);/* ToDo handle symbol */
        while (TokenType.isStatementTerminal(currentToken.getTokenType())) {
            statement();/* ToDo handle symbol */
            statements.add((Statement) currentNode);
        }
        accept(TokenType.RBRACKET);/* ToDo handle symbol */
        currentNode = new BlockNode(null, statements);
    }

    void expression() {
        simpleExpression();/* ToDo handle symbol */
        Token<TokenType> token = currentToken;
        ExpressionNode left = (ExpressionNode) currentNode;
        //currentNode points to the simpleExpression no need to assign
        if (TokenType.isRelationalOperator(currentToken.getTokenType())) {
            ExpressionNode right;
            ExpressionNode relationalOperator = null;
            accept(currentToken.getTokenType());/* ToDo handle symbol currentToken (currentToken.getTokenType()) */
            simpleExpression();/* ToDo handle symbol */

            right = (ExpressionNode) currentNode;
            switch (token.getTokenType()) {
                case EQUALS:        relationalOperator = new EqualsNode(token, left, right); break;
                case NOTEQUALS:     relationalOperator = new NotEqualNode(token, left, right); break;
                case GREATER:       relationalOperator = new GreaterNode(token, left, right); break;
                case GREATER_EQ:    relationalOperator = new GreaterOrEqualNode(token, left, right); break;
                case LESS:          relationalOperator = new LessNode(token, left, right); break;
                case LESS_EQ:       relationalOperator = new LessOrEqualNode(token, left, right); break;
            }
            currentNode = relationalOperator;
        }
    }

    void simpleExpression() {
        signedTerm();/* ToDo handle symbol */
        ExpressionNode left = (ExpressionNode) currentNode;
        //PLUS, MINUS, OR
        while (TokenType.isOperatorGroupOne(currentToken.getTokenType())) {
            Token<TokenType> token = currentToken;
            accept(currentToken.getTokenType());/* ToDo handle symbol currentToken (currentToken.getTokenType()) */
            signedTerm();/* ToDo handle symbol */
            ExpressionNode right = (ExpressionNode) currentNode;
            ExpressionNode additiveOperator = null;
            switch (token.getTokenType()) {
                case PLUS:  additiveOperator = new AdditionNode(token, left, right); break;
                case MINUS: additiveOperator = new SubtractionNode(token, left, right); break;
                case OR:    additiveOperator = new OrNode(token, left, right); break;
            }
            currentNode = left = additiveOperator;
        }
    }

    void signedTerm() {
        Token<TokenType> token = null;
        if (TokenType.isUnaryOperator(currentToken.getTokenType())) {
            token = currentToken;
            accept(currentToken.getTokenType());/* ToDo handle symbol currentToken (currentToken.getTokenType()) */
        }
        term();/* ToDo handle symbol */
        ExpressionNode operand = (ExpressionNode) currentNode;
        if (token != null) {
            switch (token.getTokenType()) {
                case NOT: operand = new NotNode(token, operand); break;
                case MINUS: operand = new MinusNode(token, operand); break;
            }
        }
        currentNode = operand;
    }

    void term() {
        factor(); /* ToDo handle symbol */
        ExpressionNode left = (ExpressionNode) currentNode;
        //MUL, DIV, MOD, AND
        while (TokenType.isOperatorGroupTwo(currentToken.getTokenType())) {
            Token<TokenType> token = currentToken;
            accept (currentToken.getTokenType()); /* ToDo handle symbol currentToken (currentToken.getTokenType()) */

            // TODO
            factor();/* ToDo handle symbol */
            ExpressionNode right = (ExpressionNode) currentNode;
            ExpressionNode multiplicativeOperator = null;
            switch (token.getTokenType()) {
                case MUL: multiplicativeOperator = new MultiplicationNode(token, left, right); break;
                case DIV: multiplicativeOperator = new DivisionNode(token, left, right); break;
                case MOD: multiplicativeOperator = new ModNode(token, left, right); break;
                case AND: multiplicativeOperator = new AndNode(token, left, right); break;
            }
            currentNode = left = multiplicativeOperator;
        }
    }

    void factor() {
        switch(currentToken.getTokenType()) {
            case IDENTIFIER:    variable(); /* ToDo handle symbol */
                                break;
            case NUMBER:        currentNode = new IntegerNode(currentToken);
                                accept(TokenType.NUMBER);/* ToDo handle symbol */
                                break;
            case TRUE:
            case FALSE:         currentNode = new BooleanNode(currentToken);
                                accept(currentToken.getTokenType());/* ToDo handle symbol currentToken (currentToken.getTokenType()) */
                                break;
            case LENGTH:        arrayLength();/* ToDo handle symbol */
                                break;
            case LPAREN:        accept(TokenType.LPAREN);/* ToDo handle symbol */
                                expression(); /* ToDo handle symbol */
                                accept(TokenType.RPAREN);/* ToDo handle symbol */
                                break;
            case AT:            functionCall(); /* ToDo handle symbol */
                                break;
            default:   throw new SyntaxException("Expected factor. Got " + currentToken.getTokenType().value, currentToken);
        }
    }

    void variable() {
        Token token = currentToken;
        accept(TokenType.IDENTIFIER);/* ToDo handle symbol */
        ExpressionNode expression = null;
        if (currentToken.getTokenType() == TokenType.LSQUARE) {
            accept(TokenType.LSQUARE);/* ToDo handle symbol */
            simpleExpression();/* ToDo handle symbol */
            expression = (ExpressionNode) currentNode;
            accept(TokenType.RSQUARE);/* ToDo handle symbol */
        }
        currentNode = new VariableNode(token, expression);
    }

    void mainFunction() {
        Token token = currentToken;
        accept(TokenType.IDENTIFIER);/* ToDo handle symbol */
        accept(TokenType.LPAREN);/* ToDo handle symbol */
        accept(TokenType.RPAREN);/* ToDo handle symbol */
        accept(TokenType.ARROW);/* ToDo handle symbol */
        TypeNode typeNode = new VoidTypeNode(currentToken);
        accept(TokenType.VOID);/* ToDo handle symbol */
        block();/* ToDo handle symbol */
        currentNode = new FunctionDefinitionNode(token, null, typeNode, (BlockNode) currentNode);
    }

    void statement() {
        if (TokenType.isCompoundStatementTerminal(currentToken.getTokenType())) {
            compoundStatement();/* ToDo handle symbol */
        } else {
            simpleStatement();/* ToDo handle symbol */
            accept(TokenType.SEMICOLON);/* ToDo handle symbol */
        }
    }

    void simpleStatement() {
        switch(currentToken.getTokenType()) {
            case INT:
            case CHAR:
            case BOOLEAN:       variableDefinition();/* ToDo handle symbol */
                                break;
            case IDENTIFIER:    assignment();/* ToDo handle symbol */
                                break;
            case AT:            functionCall();/* ToDo handle symbol */
                                break;
            case RETURN:        returnStatement();/* ToDo handle symbol */
                                break;
            case PRINT:         printStatement();/* ToDo handle symbol */
                                break;
            case READ:          readStatement();/* ToDo handle symbol */
                                break;
            default: throw new SyntaxException("Expected simpleStatement. Got " + currentToken.getTokenType().value, currentToken);
        }
    }

    void compoundStatement() {
        if (currentToken.getTokenType() == TokenType.IF) {
            ifStatement();/* ToDo handle symbol */
        } else {
            whileStatement(); /* ToDo handle symbol */
        }
    }

    // TODO: check again.
    void ifStatement() {
        Token token = currentToken;
        accept(TokenType.IF);/* ToDo handle symbol */
        accept(TokenType.LPAREN);/* ToDo handle symbol */
        expression(); /* ToDo handle symbol */
        block();  //??

        ExpressionNode expressionNode = (ExpressionNode) currentNode;
        accept(TokenType.RPAREN);/* ToDo handle symbol */
        block();/* ToDo handle symbol */


        BlockNode ifStatement = (BlockNode) currentNode;
        BlockNode elseStatement = null;
        if (currentToken.getTokenType() == TokenType.ELSE) {
            accept(TokenType.ELSE);/* ToDo handle symbol */
            block(); /* ToDo handle symbol */
            elseStatement = (BlockNode) currentNode;
        }
        currentNode = new IfStatementNode(token, expressionNode, ifStatement, elseStatement);
    }

    // TODO - ok but check again.
    void whileStatement() {
        Token token = currentToken;
        accept(TokenType.WHILE);/* ToDo handle symbol */
        accept(TokenType.LPAREN);/* ToDo handle symbol */
        expression();/* ToDo handle symbol */
        ExpressionNode expressionNode = (ExpressionNode) currentNode;
        accept(TokenType.RPAREN);/* ToDo handle symbol */
        block();/* ToDo handle symbol */
        BlockNode blockNode = (BlockNode) currentNode;
        currentNode = new WhileStatementNode(token, expressionNode, blockNode);
    }

    void returnStatement() {
        Token token = currentToken;
        accept(TokenType.RETURN);/* ToDo handle symbol */
        AssignableNode assignable = null;
        if (TokenType.isLiteralTerminal(currentToken.getTokenType())) {
            assignable();/* ToDo handle symbol */
            assignable = (AssignableNode) currentNode;
        }
        currentNode = new ReturnStatementNode(token, assignable);
    }

    // TODO - ok but check again.
    void printStatement() {
        Token token = currentToken;
        accept(TokenType.PRINT);/* ToDo handle symbol */
        accept(TokenType.LPAREN);/* ToDo handle symbol */
        actualParameters(); /* ToDo handle symbol */
        ActualParameterNode actualParameters = (ActualParameterNode) currentNode;
        accept(TokenType.RPAREN);/* ToDo handle symbol */
        currentNode = new PrintStatementNode(token, actualParameters);
    }

    void readStatement() {
        Token token = currentToken;
        List<VariableNode> variables = new ArrayList<>();
        accept(TokenType.READ);
        accept(TokenType.LPAREN);
        while (currentToken.getTokenType() == TokenType.IDENTIFIER) {
            variable();
            variables.add((VariableNode) currentNode);
        }
        accept(TokenType.RPAREN);
        currentNode = new ReadStatementNode(token, variables);
    }

    void assignable() {
        if (TokenType.isFactorTerminal(currentToken.getTokenType())) {
            expression();
        } else if (TokenType.isPrimitiveType(currentToken.getTokenType())) {
            arrayInitialization();
        } else if (TokenType.CHAR_LITERAL == currentToken.getTokenType()) {
            characterLiteral();
        } else {
            stringLiteral();
        }
    }

    void characterLiteral() {
        currentNode = new CharacterLiteralNode(currentToken);
        accept(TokenType.CHAR_LITERAL);
    }
	
	void stringLiteral() {
        currentNode = new StringLiteralNode(currentToken);
        accept(TokenType.STRING_LITERAL);
	}

    void arrayLength() {
        Token token = currentToken;
        accept(TokenType.LENGTH);/* ToDo handle symbol */
        accept(TokenType.LPAREN);/* ToDo handle symbol */
        variable();/* ToDo handle symbol */
        accept(TokenType.RPAREN);/* ToDo handle symbol */
        currentNode = new ArrayLengthNode(token, (VariableNode) currentNode);
    }

    public static void main(String[] args) throws IOException {
//        Lexer<TokenType> lexer = new LexerImpl(new SourceImpl("C:\\Users\\Boris\\Documents\\Github\\University\\Compilers and interpreters\\Compiler_students\\resources\\Fib.txt"));
//        Parser<TokenType, AST> parser = new ParserImpl(lexer);
//        System.out.println(CompilerTestHelper.getASTasString(parser));

        Lexer<TokenType> lexer = new LexerImpl(new SourceImpl("C:\\Users\\Boris\\Documents\\Github\\University\\Compilers and interpreters\\Compiler_students\\resources\\Lab_4_Exer-4_c.txt"));
        Parser<TokenType, AST> parser = new ParserImpl(lexer);
        System.out.println(CompilerTestHelper.getASTasString(parser));
    }
}
