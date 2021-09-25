import java.util.*;
import java.io.*;

public class sushi 
{
   public static int      PEOPLE_PER_CAR = 4;
   
   
   public sushi() throws FileNotFoundException
   {
      int         numTestCases;
      int         curTestCase;
      Scanner     sc;
      int         numOfCars;
      int         numOfPeople;
      Integer[]   listOfCarTime;
      Integer[]   listOfEatingTime;
      int         curPerson;
      int         curCar;
      int         slowestTime;
      int         curTime;
      
      // Use a scanner to read in the file
      sc = new Scanner(System.in);
      
      // Get the number of cars and the number of people
      numOfCars = sc.nextInt();
      numOfPeople = numOfCars * PEOPLE_PER_CAR;
         
      // Allocate memory for the list of the driving times
      listOfCarTime = new Integer[numOfCars];
         
      // Allocate memory for the list of the driving times
      listOfEatingTime = new Integer[numOfPeople];

      // Read in the cars
      for (curCar = 0; curCar < numOfCars; curCar++)
      {
         // Read in another car
         listOfCarTime[curCar] = sc.nextInt();
      }

      // Read in the people
      for (curPerson = 0; curPerson < numOfPeople; curPerson++)
      {
         // Read in another team member
         listOfEatingTime[curPerson] = sc.nextInt();
      }
         
      // Sort the cars
      Arrays.sort(listOfCarTime);
         
      // Sort the team members
      Arrays.sort(listOfEatingTime, Collections.reverseOrder());
         
      // Start the slowest person as no time
      slowestTime = 0;
         
      // Look at each person and assign them to a car greedily
      for (curPerson = 0; curPerson < numOfPeople; curPerson++)
      {
         // Get the car that the person should be assigned to
         curCar = curPerson / PEOPLE_PER_CAR;
            
         // Get the time for the current combination
         curTime = listOfCarTime[curCar] + listOfEatingTime[curPerson];
         
         // Check if the time is slower than the slowest time
         if (slowestTime < curTime)
         {
            // Update the slowest time
            slowestTime = curTime;
         }
      }
      
      // Output the slowest time
      System.out.printf("%d%n", slowestTime);
   }
   
   
   // The main method
   public static void main(String[] Args) throws FileNotFoundException
   {
      new sushi();
   }
}
