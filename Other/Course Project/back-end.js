const keywordsArray = ['abstract', 'as', 'base', 'bool', 'break', 'byte', 'case', 'catch', 'char', 'checked', 'class', 'const', 'continue', 'decimal', 'default', 'delegate', 'double', 'do', 'else', 'enum', 'event', 'explicit', 'extern', 'false', 'finally', 'fixed', 'float', 'for', 'foreach', 'goto', 'if', 'implicit', 'int', 'interface', 'internal', 'is', 'lock', 'long', 'namespace', 'new', 'null', 'object', 'operator', 'override', 'params', 'private', 'protected', 'public', 'readonly', 'ref', 'return', 'sbyte', 'sealed', 'short', 'sizeof', 'stackalloc', 'static', 'string', 'struct', 'switch', 'this', 'throw', 'true', 'try', 'typeof', 'uint', 'ulong', 'unchecked', 'unsafe', 'ushort', 'using', 'using static', 'virtual', 'void', 'volatile', 'while', 'System', 'out', 'println'];
const identifiersArray = ['public function', 'int', 'double', 'decimal', 'string', 'char', 'public class'];
const operatorsArray = ['+', '-', '*', '/', '=', '>', '<', '&', ',', '%', '!=', '*=', '/=', '-=', '+=', '--', '++'];
const delimitersArray = [',', ';', '.', '{', '}', '(', ')'];

function extractTerms() {
    document.getElementById('submit').addEventListener('click', () => {
        let inputAsString = document.getElementById('inputField').value;
        let output = '';

        inputAsString = splitCode(inputAsString);

        inputAsString
            .split(/\s+/)
            .map((element) => {
                if (keywordsArray.includes(element)) {
                    output += `${element} is keyword\n`;
                } else if (identifiersArray.includes(element)) {
                    output += `${element} is identifier\n`;
                } else if (!isNaN(element) || (element.startsWith("'") && element.endsWith("'") || (element.startsWith('"') && element.endsWith('"')))) {
                    output += `${element} is constant\n`;
                } else if (operatorsArray.includes(element)) {
                    output += `${element} is operator\n`;
                } else if (delimitersArray.includes(element)) {
                    output += `${element} is delimiter\n`;
                } else {
                    output += `${element} is identificator\n`;
                }
            });

        document.getElementById("outputField").value = output;
    });
}

function splitCode(code) {
    let splittedCode = '';

    code
        .split('')
        .map((element) => {
            if (operatorsArray.includes(element) || delimitersArray.includes(element)) {
                splittedCode += ' ' + element + ' ';
            } else if (element === '\n') {
                splittedCode += ' ';
            } else {
                splittedCode += element;
            }
        });

    return splittedCode.trim('\n');
}