package xml;

import models.User;
import models.UserRepository;
import models.UsersListXML;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collection;

public class XMLWorker {
    public void writeToXMLFile(String xmlFile, Collection<User> users) throws JAXBException {
        UsersListXML usersListXML = new UsersListXML();
        usersListXML.setUsers(new ArrayList<User>(users));

        // Създаване на JAXB контекст
        JAXBContext context = JAXBContext.newInstance(UsersListXML.class);
        // Създаване на marshaller инстанция (ot java v xml)
        Marshaller m = context.createMarshaller();
        m.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, Boolean.TRUE);
        // Записване в System.out
        m.marshal(usersListXML, System.out);
        // Записване във файл
        m.marshal(usersListXML, new File(xmlFile));
    }

    public UsersListXML readerFromXMLFile(String xmlFile) throws JAXBException, FileNotFoundException {

        // Създаване на JAXB контекст
        JAXBContext context = JAXBContext.newInstance(UsersListXML.class);
        // Създаване на unmarshaller инстанция (from xml v java object)
        Unmarshaller um = context.createUnmarshaller();
        UsersListXML group = (UsersListXML) um.unmarshal(new FileReader(xmlFile)); // zaregdame ot file

        return group;
    }
}
