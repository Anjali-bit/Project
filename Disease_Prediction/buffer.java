import java.io.*;
class Buffer
{
public static void main(String[]args) throws IOException
{
    try{
FileInputStream f1 = new FileInputStream ("e:/java/iohand/dispfile/nos.txt");}
    catch(Exception e){


BufferedInputStream b1 = new BufferedInputStream (f1); 
int l;
l=b1.available();
int i=1;
char ch;
while(i<=l/2)
{
ch = (char)b1.read(); 
System.out.print(ch);
i++;
}
b1.skip(4); 
i=i+4; 
while(i<=l)
{
ch = (char)b1.read(); 
System.out.print(ch);
i++;
}
System.out.println("\n\nNo. of bytes stored in this file = "+l+".");
boolean m;
m=b1.markSupported();
System.out.println("\nThis stream supports mark() and reset() = "+m+".");
b1.close();
}}
}