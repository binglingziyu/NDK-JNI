package com.ihubin.ndkjni;

import java.security.MessageDigest;

public class HashUtil {

    public static String md5(String plainText) {
        try {
            MessageDigest md5 = MessageDigest.getInstance("MD5");
            byte[] md5Byte = md5.digest(plainText.getBytes());
            return byteArrayToString(md5Byte);
        } catch (Exception e) {
            return "";
        }
    }

    public static String sha1(String plainText) {
        try {
            MessageDigest sha1 = MessageDigest.getInstance("SHA1");
            byte[] sha1Byte = sha1.digest(plainText.getBytes());
            return byteArrayToString(sha1Byte);
        } catch (Exception e) {
            return "";
        }
    }

    public static String sha256(String plainText) {
        try {
            MessageDigest sha256 = MessageDigest.getInstance("SHA256");
            byte[] sha256Byte = sha256.digest(plainText.getBytes());
            return byteArrayToString(sha256Byte);
        } catch (Exception e) {
            return "";
        }
    }

    private static String byteArrayToString(byte[] array) {
        StringBuilder hexString = new StringBuilder();
        for (int i = 0; i < array.length; i++) {
            String appendString = Integer.toHexString(0xFF & array[i]).toUpperCase();
            if (appendString.length() == 1)
                hexString.append("0");
            hexString.append(appendString);
            if(i < array.length - 1)
                hexString.append(":");
        }
        return hexString.toString();
    }

}
