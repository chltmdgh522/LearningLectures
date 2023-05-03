package ex.java9.animal;

public class Ame {
    public static void main(String[] args) {
        Dog dog= new Dog();
        dog.sound();

        Cat cat = new Cat();
        cat.sound();

        animalSound(new Dog());

    }
    
    public static void animalSound(Animal animal){
        animal.sound();
    }
}
