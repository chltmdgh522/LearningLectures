package ex.java9.animal;

public class Ame {
    public static void main(String[] args) {
        Dog dog= new Dog();
        dog.sound();

        Cat cat = new Cat();
        cat.sound();

        Ame ame =new Ame();
        ame.animalSound(new Dog());

    }

    public void animalSound(Animal animal){
        animal.sound();
    }
}
