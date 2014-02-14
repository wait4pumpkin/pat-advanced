import java.util.List;
import java.util.LinkedList;

/**
 * Created by pumpkin on 1/27/14.
 */
public class Main {
    public static void main(String[] args) {
        Stack stack = new Stack();

    }
}

class Stack {
    public Integer push(Integer i) {
        list.add(i);
    }

    public Integer pop() {
        if (list.size() <= 0) return null;
        int i = list.get(list.size() - 1);
        list.remove(list.size() - 1);
        return i;
    }

    public Integer popMediean() {

    }

    private List<Integer> list = new LinkedList<Integer>();
}