public class Herencia {
    public static void main(String[] args)
    {
        // Crear un objeto de la clase hija
        Dog dog = new Dog("Balto");
        dog.bark();
        dog.eat();

        Cat cat = new Cat("Tom");
        cat.meow();
        cat.eat();
    }

    // Clase padre
    static class Animal {
        String name;

        Animal(String name) {
            this.name = name;
        }
    
        void eat() {
            System.out.println(name + " is eating...");
        }
    }

    // Clase hija
    static class Dog extends Animal {
        Dog(String name) {
            super(name);
        }
        void bark() {
            System.out.println(name + " is barking...");
        }
    }

    // Clase hija
    static class Cat extends Animal {
        Cat(String name) {
            super(name);
        }
        void meow() {
            System.out.println(name + " is meowing...");
        }
    }

    // Clase hija
    static class Lion extends Animal {
        Lion(String name) {
            super(name);
        }
        void meow() {
            System.out.println(name + " is roaring...");
        }
    }
}
