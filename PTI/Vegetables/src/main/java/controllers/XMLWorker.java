package controllers;

import models.VegetablesRepository;

import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import java.io.File;

public class XMLWorker {
    private static String filePath = "C:\\Users\\Boris\\Desktop\\Java_Projects\\Vegetables\\src\\main\\webapp\\vegetables.xml";

    public static void writer(VegetablesRepository vegetables) {
        try {
            JAXBContext context = JAXBContext.newInstance(VegetablesRepository.class);
            Marshaller marshaller = context.createMarshaller();
            marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, Boolean.TRUE);
            marshaller.marshal(vegetables, new File(filePath));
        } catch (JAXBException e) {
            e.printStackTrace();
        }
    }
}
