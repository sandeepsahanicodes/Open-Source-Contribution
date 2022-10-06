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
   
   // Added a div method for division
   public static int div(int a,int b)
   {
      int q=0;
      if(b==0)
      {
        System.out.println("Please add a non-zero denominator");
      }
      else
      {
         q=a/b;
      }
      return q;
   }

}
// Driver class
class MathDriver
{
    public static void main(String[] args) 
    {
        System.out.println(MyMath.add(10, 20));
        System.out.println(MyMath.sub(10, 20));
        System.out.println(MyMath.div(10, 20)); // Using div method
    }
}
