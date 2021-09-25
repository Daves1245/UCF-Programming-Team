import java.util.*;
import java.io.*;

public class microwave 
{
   public static int      SECOND_START_POS = 3;
   public static int      SECOND_END_POS = 5;
   public static int      MINUTE_START_POS = 0;
   public static int      MINUTE_END_POS = 2;
   public static int      MAX_ENTRY = 9999;
   public static int      SECONDS_IN_MINUTE = 60;
   public static int      MINUTE_VALUE_IN_PRESS = 100;
   public static int      LARGE_VALUE = 100;
   
   
   // Microwave: The magic happens here
   public microwave() throws FileNotFoundException 
   {
      int       numTestCases;
      int       curTestCase;
      Scanner   sc;
      String    timeNeeded;
      int       secondsNeeded;
      int       percentage;
      int       minTime;
      int       maxTime;
      int       bestEffort;
      int       bestPress;
      int       bestActualTime;
      int       curEffort;
      int       curPress;
      int       curActualTime;
      
      // Use a scanner to read in the file
      sc = new Scanner(System.in);
   
      // Read in the testcase
      timeNeeded = sc.next();
      percentage = sc.nextInt();

      // Initialize the best values with "bad" values
      bestEffort = LARGE_VALUE;
      bestPress = -1;
      bestActualTime = -1;
      
      // Get the actual time in seconds
      secondsNeeded = getSecondFromFormattedString(timeNeeded);
      
      // Get the max time and the minimum time (both in seconds)
      maxTime = secondsNeeded + ((percentage * secondsNeeded) / 100);
      minTime = secondsNeeded - ((percentage * secondsNeeded) / 100);
      
      // Loop through all possible presses
      for (curPress = 0; curPress <= MAX_ENTRY; curPress++)
      {
         // Get the effort and the actual time
         curEffort = getEffort(curPress);
         curActualTime = convertIntToSeconds(curPress);
         
         // Check if the best effort is not as good as the current one
         if (curEffort < bestEffort && curActualTime >= minTime && 
               curActualTime <= maxTime)
         {
            // Update the best values
            bestActualTime = curActualTime;
            bestEffort = curEffort;
            bestPress = curPress;
         }
         else if (curEffort == bestEffort && curActualTime >= minTime && 
               curActualTime <= maxTime)
         {
            // Check the tie breaking case
            if (Math.abs(curActualTime - secondsNeeded) < 
                  Math.abs(bestActualTime - secondsNeeded))
            {
               // Update the best values
               bestActualTime = curActualTime;
               bestEffort = curEffort;
               bestPress = curPress;
            }
         }
      }
         
      // Output the results
      System.out.printf("%d%n", bestPress);
   }
   
   
   // Get the amount of effort for a given press
   private int getEffort(int curPress) {
      String   pressString;
      int      effortValue;
      int      curDigit;
      
      // Get the press as a String
      pressString = Integer.toString(curPress);
      
      // Start the effort as the length of the string
      effortValue = pressString.length();
      
      // Look at all pairs of digits
      for (curDigit = 0; curDigit < pressString.length(); curDigit++)
      {
         // Check that there is another digit
         if (curDigit + 1 < pressString.length())
         {
            // Check if the pair is different and if so update the effort
            if (pressString.charAt(curDigit) != 
                  pressString.charAt(curDigit + 1))
               effortValue++;
         }
      }
      
      // Return the effort value
      return effortValue;
   }


   // Get the number of seconds from a press
   private int convertIntToSeconds(int curPress) {
      int      totalSeconds;
      int      minutesInt;
      int      secondsInt;
      
      // Convert the Strings to integers
      secondsInt = curPress % MINUTE_VALUE_IN_PRESS;
      minutesInt = curPress / MINUTE_VALUE_IN_PRESS;
      
      // Get the total number of seconds for the given string
      totalSeconds = secondsInt + (SECONDS_IN_MINUTE * minutesInt);
      
      // Return the time
      return totalSeconds;
   }


   // Get the number of seconds from a formatted press
   private int getSecondFromFormattedString(String secondsNeeded) {
      int      totalSeconds;
      int      minutesInt;
      int      secondsInt;
      String   secondsString;
      String   minutesString;

      // Get the string of the number os minutes and the number of seconds
      secondsString = secondsNeeded.substring(SECOND_START_POS, SECOND_END_POS);
      minutesString = secondsNeeded.substring(MINUTE_START_POS, MINUTE_END_POS);
      
      // Convert the Strings to integers
      secondsInt = Integer.parseInt(secondsString);
      minutesInt = Integer.parseInt(minutesString);
      
      // Get the total number of seconds for the given string
      totalSeconds = secondsInt + (SECONDS_IN_MINUTE * minutesInt);
      
      // Return the time
      return totalSeconds;
   }


   // Do the main thing
   public static void main(String[] Args) throws FileNotFoundException
   {
      // Instantiate a run of microwave
      new microwave();
   }
}
