#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;




// Author: Domenico Di Piazza
// 5/14/2025
// This whole program is inspried by the template made by Tianna Coburn, from a presentation she gave on 5/14/2025.

/*

Dear <Hiring Manager>,

My name is <Name> and I am applying to <position> due to <passion, experience, etc.>

My experience with <role, job> prepares me for <position>. <Explain experience, how it connects to role>

Additionally, in my role as <role, job>, I have learned skills such as <skills>. <Expound on how you have applied these skills>. 
I am excited for the opportunity to further apply these skills in <position>.

Thank you for your consideration. I am happy to provide references upon request. 
If you have any further questions, please feel free to contact me at <contact details>.

Best,
<Full Name>

*/

string get_good_str (){
    string user_str;
    int i; // i is an index/location in the string
    do{
        getline(std::cin, user_str); //reads characters until whitespace
        // for all characters in the string from 0 to length-1
        for(i=0; i< user_str.length(); i++){
            //error if a character is not between 0 and 5 on the ASCII chart
            if(user_str.at(i) < 'A' || user_str.at(i) > 'z'){
                if((user_str.at(i) =! " ") && (user_str.at(i) =! "-")&& (user_str.at(i) =! "'") && (user_str.at(i) =! "@")&& (user_str.at(i) =! ".")){
                    cout << "Error. please enter a valid string (no letters/special characters): ";
                    break; // get out of the loop because we know there has been an error
                }
            }
        }
    }while(i<user_str.length()); // i is equal to the length if not an error
    return (user_str); // return string
}

string get_entry_or_default (string default_string){
    string user_str;
    
    user_str += (get_good_str());

    if(user_str.length() > 0){
        return (user_str); // return string
    }
    else{
        return default_string;
    }
}

int main() {
    std::ofstream outputFile("coverLetter.txt");

    cout << "Enter the Hiring Manager's name. If unknown, simply press ENTER: ";
    string hiringManager = get_entry_or_default("Hiring Manager");

    cout << "Enter your preferred name: ";
    string prefName = get_good_str();

    cout << "Enter your full name: ";
    string fullName = get_good_str();

    cout << "Enter your professional email: ";
    string email;
    getline(std::cin, email);

    cout << "Enter your phone number. If you want to leave this blank, simply press ENTER: ";
    string phoneNumber;
    getline(std::cin, phoneNumber);

    cout << "Enter the name of the position: ";
    string positionApplying = get_good_str();

    cout << "Reason for applying. \nContext: I am applying for the " << positionApplying << " position due to: ";
    string reasonForApplying = get_good_str();

    cout << "Name a previous position you held that prepared you for this one: ";
    string prevPosition1 = get_good_str();

    cout << "What did you do as a " << prevPosition1 << "? (full sentence, with capitalization and punctuation): ";
    string posExplanation1;
    getline(std::cin, posExplanation1);

    cout << "How does that connect to being a " << positionApplying << "? (full sentence, with capitalization and punctuation): ";
    string connection;
    getline(std::cin, connection);


    cout << "What company/organization was that with? ";
    string prevCompany1;
    getline(std::cin, prevCompany1);

    cout << "Name a second previous position you held that prepared you for this one: ";
    string prevPosition2 = get_good_str();

    cout << "What did you do as a " << prevPosition2 << "? (full sentence, with capitalization and punctuation): ";
    string posExplanation2;
    getline(std::cin, posExplanation2);

    cout << "Name a skill that you learned doing those things: ";
    string skill1 = get_good_str();

    cout << "Name another skill that you learned doing those things: ";
    string skill2 = get_good_str();

    cout << "What company/organization was that with? ";
    string prevCompany2;
    getline(std::cin, prevCompany2);



    
    if (outputFile.is_open()) {

        outputFile << "Dear " << hiringManager << ",\n" << endl;
        outputFile << "My name is " << prefName << " and I am applying for the " << positionApplying;
        outputFile << " position due to " << reasonForApplying << ". \n";
        outputFile << "My experience with " << prevCompany1 << " as a " << prevPosition1 << " prepared me to be a " << positionApplying << ". \n";
        outputFile << posExplanation1 << "\n " << connection << "\n" << endl;
        outputFile << "Additionally, in my role as a " << prevPosition2 << " at " << prevCompany2 << ", \n I learned skills such as ";
        outputFile << skill1 << " and " << skill2 << ". \n " << posExplanation2 << "\n" << endl;
        outputFile << "I am excited for the opportunity to further apply these skills as a " << positionApplying << "." << endl;
        outputFile << "Thank you for your consideration. I am happy to provide references upon request. \n"; 
        outputFile << "If you have any further questions, please feel free to contact me at " << email <<".\n" << endl;

        outputFile << "Best, \n" << fullName << "\n" << phoneNumber;
        outputFile.close();
    } else {
        // Handle the error
        cout << "Could not access file" << endl;
    }
    return 0;
}