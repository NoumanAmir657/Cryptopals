package com.company;

public class Main {

    public static void main(String[] args) {
        StringBuilder s = new StringBuilder();
        s.append("YELLOW SUBMARINE");
        System.out.println(padding(s));
    }
    public static String padding(StringBuilder s){
        int blockSize = 20;
        int length = s.toString().length();
        int bytesToAdd = (blockSize - length);
        if (bytesToAdd==0){
            bytesToAdd=20;
        }
        System.out.println(Integer.toHexString(bytesToAdd));
        for (int i = 0; i < bytesToAdd; ++i){
            s.append(Integer.toHexString(bytesToAdd));
        }
        return s.toString();
    }
}
