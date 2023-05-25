package intermediate.poweroftwo;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<TypedElement> recorder = new ArrayList<TypedElement>();

        recorder = exponentialForm(n,recorder);
        printExponentialForm(recorder);
    }

    private static class TypedElement {
        private final Object element;
        private final Class<?> type;

        public TypedElement(Object element, Class<?> type) {
            this.element = element;
            this.type = type;
        }

        public Object element() {
            return element;
        }

        public Class<?> type() {
            return type;
        }
    }
    public static ArrayList<TypedElement> exponentialForm(int n, ArrayList<TypedElement> recorder){
        int count = 0;
        for (int i = 2; i <= n; i *= 2) {
            count++;
        }
        TypedElement countElement = new TypedElement(count,Integer.class);
        recorder.add(countElement);

        int reminder = (int)(n - Math.pow(2,count));
        if (reminder != 0) return exponentialForm(reminder,recorder);
        else {
            for (int i = 0; i < recorder.size(); i++){
                TypedElement aux1 = recorder.get(i);
                int aux = (int) aux1.element();
                ArrayList<TypedElement> auxArray = new ArrayList<TypedElement>();

                if (aux > 1) {
                    auxArray = exponentialForm(aux,auxArray);
                    TypedElement auxArrayElement = new TypedElement(auxArray,ArrayList.class);
                    recorder.set(i,auxArrayElement);
                }

            }
            return recorder;
        }
    }

    public static void printExponentialForm(ArrayList<TypedElement> recorder){
        for (int i = 0; i < recorder.size(); i++) {
            TypedElement aux = recorder.get(i);

            if (aux.type == ArrayList.class) {
                ArrayList auxArrayList = (ArrayList) aux.element();

                System.out.print("2(");
                printExponentialForm(auxArrayList);
                System.out.print(")");
            } else {
                int auxInteger = (int)aux.element();

                System.out.print("2");
                if (auxInteger == 0) {
                    System.out.print("(" + auxInteger + ")");
                }
            }

            int size = recorder.size();
            printPlusMark(i,size);

        }
    }

    public static void printPlusMark(int i,int size) {
        if(i < size - 1) System.out.print("+");
    }
}
