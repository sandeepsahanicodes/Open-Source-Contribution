// Math class
class MyMath
{
   public static int add(int a,int b)
   {
       return a+b;
   }

   public static int sub(int a,int b)
   {
       return a-b; // Bug
   }
   
   // Added a div method for division
   public static int div(int a,int b)
   {
      return (b!=0) ? (a/b): -1;
   }

}
// Driver class
class MathDriver
{
    public static void main(String[] args) 
    {
        System.out.println(MyMath.add(10, 20));
        System.out.println(MyMath.sub(10, 20));
        System.out.println(MyMath.div(20, 0)); // Using div method
    }
}
