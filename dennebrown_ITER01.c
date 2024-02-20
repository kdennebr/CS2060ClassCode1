 //
//  DenneBrownKayden_ProjectIteration01.c
//  CS2060Project
//
//  Created by Kayden Brown on 2/10/24.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND_MINUTES_FACTOR 1.2
#define MAX_RAND_MINUTES_FACTOR 1.5

#define SENTINAL_VALUE -1

int main(void){
    //Base Values
    int minMiles = 1;
    int maxMiles = 100;
    
    double baseFare = 1.8;
    double costPerMinute = .25;
    double costPerMile = 1.2;
    double minFlatRate = 20.0;
    double numMiles = 0.0;
    
    
    //Counter Values
    double totalMiles = 0.0;
    double totalPrice = 0;
    int totalMinutes = 0;
    int numRides = 0;
    
    //Valid Input Boolean
    bool validInput = false;
    
    
    //Prototyping Functions
    void displayPricing(int, int, double, double, double, double);
    void displayFinalMenu(int, double, int, double);
    
    double numOfEstimatedMinutes(double);
    double calcFare(double, double, double, double, double, int);
    
    void displayRideInformation(int, double, double, double);
    
    bool validateInput(int miles, int minMiles, int maxMiles);
    
    do {
        int scanFReturn = 0;
        
        displayPricing(minMiles, maxMiles, baseFare, costPerMinute, costPerMile, minFlatRate);
        
        puts("\nEnter Number of Miles");
        
        scanFReturn = scanf("%lf", &numMiles);
        
        if(scanFReturn == 1){
            validInput = validateInput(numMiles, minMiles, maxMiles);
           
            if(validInput){
               
                if(numMiles == SENTINAL_VALUE){
                     displayFinalMenu(numRides, totalMiles, totalMinutes, totalPrice);
                 }
                else{
                    
                    numRides++;
                    totalMiles += numMiles;
                    
                    int numMinutes = 0;
                    
                    numMinutes = numOfEstimatedMinutes(numMiles);
                    
                    totalMinutes += numMinutes;
                    
                    
                    double ridePrice = 0.0;
                    
                    ridePrice = calcFare(baseFare, costPerMinute, costPerMile, minFlatRate, numMiles, numMinutes);
                    
                    totalPrice += ridePrice;
                    
                    displayRideInformation(numRides, numMiles, numMinutes, ridePrice);
                }
            }
            else{
                puts("Please Enter a Number in the Range");
            }
        }
        else{
            puts("Please enter a number");
            getchar();
        }
        
    }while(numMiles != SENTINAL_VALUE);
    
 
   
    return 1;
}

void displayPricing(int minMiles, int maxMiles, double baseFare, double costPerMinute, double costPerMile, double minFlatRate){
    
    printf("\n\nWelcome to the UCCS Ride Share. We can only provide services for rides from %d to %d miles. Enter the number of miles to your destination.\n\n", minMiles, maxMiles);
    
    puts("Pricing");
    
    printf("Base (or initial) fare = $%.2f\n", baseFare);
    printf("Cost per minute = $%.2f\n", costPerMinute);
    printf("Cost per mile = $%.2f\n", costPerMile);
    printf("Minimum flat rate = $%.2f\n", minFlatRate);
    
}

double numOfEstimatedMinutes(double miles){
    //srand(time(NULL));
    
    const double minMinutes = MIN_RAND_MINUTES_FACTOR * miles;
    const double maxMinutes = MAX_RAND_MINUTES_FACTOR * miles;
    
    double range = maxMinutes - minMinutes;
    
    double div = RAND_MAX / range;
    
    double ranNum = 0.0;
    ranNum = minMinutes + (rand() / div);
    
    return ranNum;
}

void displayRideInformation(int riders, double miles, double minutes, double price){
    puts("Current Ride Information\n");
    puts("Rider \t Number of Miles \t Number of Minutes \t Ride Fare Amount");
    
    printf("%d \t\t %.2f \t\t\t\t %.2f \t\t\t\t %.2f", riders, miles, minutes, price);
}

double calcFare(double base, double minuteCost, double mileCost, double minRate, double miles, int minutes){
    double price = 0.0;
    double totalCostMinutes = 0;
    totalCostMinutes = minutes * minuteCost;
    
    double totalCostMile = 0;
    totalCostMile = miles * mileCost;
    
    price = base + totalCostMile + totalCostMinutes;
    
    if(price < minRate){
        price = minRate;
    }
    
    return price;
}



void displayFinalMenu(int riders, double miles, int minutes, double price){
    puts("UCCS Ride Share Business Summary\n");
    if(riders == 0){
        puts("No rides to show");
    }
    else{
        puts("Rider \t Number of Miles \t Number of Minutes \t Ride Fare Amount");
        printf("%d \t %.2f \t\t\t %d \t\t\t %.2f", riders, miles, minutes, price);
    }
    
}


bool validateInput(int miles, int minMiles, int maxMiles){

    bool valid = false;
    
    double mileDouble = (double) miles;
    
    if(mileDouble > minMiles & mileDouble < maxMiles){
        valid = true;
    }
    else if(mileDouble == SENTINAL_VALUE){
        valid = true;
    }
    else{
        valid = false;
    }
    
    return valid;
}


