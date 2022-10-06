// Math class
class MyMath
{
   public static int add(int a,int b)
   {
       return a+b;
   }

   public static int sub(int a,int b)
   {
       return a-b;
   }
}
// Driver class
class MathDriver
{
    public static void main(String[] args) 
    {
        System.out.println(MyMath.add(10, 20));
        System.out.println(MyMath.sub(10, 20));
    }
}