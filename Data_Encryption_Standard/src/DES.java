import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Scanner;
class DesEncrypter {
  Cipher ecipher;

  Cipher dcipher;

  DesEncrypter(SecretKey key) throws Exception {
    ecipher = Cipher.getInstance("DES");
    dcipher = Cipher.getInstance("DES");
    ecipher.init(Cipher.ENCRYPT_MODE, key);
    dcipher.init(Cipher.DECRYPT_MODE, key);
  }

  public String encrypt(String str) throws Exception {
    // Encode the string into bytes using utf-8
    byte[] utf8 = str.getBytes("UTF8");

    // Encrypt
    byte[] enc = ecipher.doFinal(utf8);

    // Encode bytes to base64 to get a string
    return new sun.misc.BASE64Encoder().encode(enc);
  }

  public String decrypt(String str) throws Exception {
    // Decode base64 to get bytes
    byte[] dec = new sun.misc.BASE64Decoder().decodeBuffer(str);

    byte[] utf8 = dcipher.doFinal(dec);

    // Decode using utf-8
    return new String(utf8, "UTF8");
  }
}

public class DES {
  public static void main(String[] argv) throws Exception {
	  String message;
	  Scanner s=new Scanner(System.in);
    SecretKey key = KeyGenerator.getInstance("DES").generateKey();
    DesEncrypter encrypter = new DesEncrypter(key);
    System.out.println("Enter the plain text");
    message=s.next();
    String encrypted = encrypter.encrypt(message);
    System.out.println("The Encrypted text is "+ encrypted);
    String decrypted = encrypter.decrypt(encrypted);
    System.out.println("The Decrypted text is "+ decrypted);
    s.close();
  }
}
