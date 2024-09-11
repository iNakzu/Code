/*
    Objetivo: Discutir y analizar los TDA (tipos de dato abstracto): set, map, bag.
    Comprender la eficencia y casos de uso de cada TDA.
*/

import java.util.Set;
import java.util.Map;
import java.util.HashSet;
import java.util.HashMap;

public class Class_06_07_2024
{
    public static void main(String[] args) {
        // Set
        Set<String> set = new HashSet<>();
        set.add("Apple");
        set.add("Banana");
        set.add("Orange");
        System.out.println("Set: " + set);

        // Map
        Map<String, Integer> map = new HashMap<>();
        map.put("Apple", 1);
        map.put("Banana", 2);
        map.put("Orange", 3);
        System.out.println("Map: " + map);
    }
}