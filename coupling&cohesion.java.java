/*************************PROBLEM STATEMENT************
Write a Java program which will demonstrate a concept of cohesion and coupling of the various modules in the program.*/
//tight coupling 
class Volume  
{ 
     public static void main(String args[])  
     { 
         Box b = new Box(5,5,5); 
         System.out.println(b.volume); 
     } 
} 
class Box  
{ 
     public int volume; 
     Box(int length, int width, int height)  
     { 
         this.volume = length * width * height; 
     } 
} 
// loose coupling
class Volume2  
{ 
     public static void main(String args[])  
     { 
         Box2 b = new Box2(5,5,5); 
         System.out.println(b.getVolume()); 
     } 
} 
final class Box2  
{ 
     private int volume; 
     Box2(int length, int width, int height)  
     { 
         this.volume = length * width * height; 
     } 
     public int getVolume()  
     {  
         return volume;   
     } 
} 
// Java program to illustrate cohesion
class Name { 
	String name; 
	public String getName() 
	{ 
		return this.name; 
	}
	public void setName(String name){
		this.name = name; 
	}
} 

class Age { 
	int age; 
	public int getAge() 
	{ 
		return this.age; 
	}
	public void setAge(int age){
		this.age = age; 
	}
} 

class Number { 
	int mobileno; 
	public int getNumber() 
	{ 
		return this.mobileno; 
	}
	public void setNumber(int mobileno){
		this.mobileno = mobileno;
	}
}

class Display {
	public static void main(String[] args) 
	{ 
		Name n = new Name();
		Age a = new Age();
		Number nu = new Number();
		n.setName("Bhaskar");
		a.setAge(20);
		nu.setNumber(21221221);
		System.out.println(n.getName());
		System.out.println(a.getAge());
		System.out.println(nu.getNumber());
	}
}
