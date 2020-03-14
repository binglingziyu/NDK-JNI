package com.ihubin.ndkjni;

public class User {

    public static int staticField = 88;

    public int normalField = 99;

    public static String getStaticUserInfo() {
        return "[name:hubin, age:18]";
    }

    public String getNormalUserInfo() {
        return "[name:hubin, age:28]";
    }


    private String name;

    private int age;

    public User() {}

    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getFormatInfo() {
        return String.format("[name:%s, age:%d]", name, age);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}
