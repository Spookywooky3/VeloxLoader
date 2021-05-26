#include "auth.h"

#include <iostream>
#include <Windows.h>
#include <tchar.h>

/*
    TODO:
        DLL INJECTION
        ANTI DEBUGGING
        ANTI REVERSAL
*/

using namespace std;
int main()
{   
    // Max size 30, doubt anyone will ever need anything bigger
    char username[30];
    char password[30];

    // Get user input
    cout << "Username: ";
    cin.getline( username, 30 );
    system( "cls" );
    cout << "Password: ";
    cin.getline( password, 30 );

    // Check credentials
    Authentication auth;
    if ( auth.AuthUser( username, password ) == false ) {
        MessageBox( NULL, _T( "Invalid Credentials!" ), _T( "Something Went Wrong!" ), MB_OK );
        return 0;
    }
    
    cout << "Welcome! Injecting..." << endl;

    // Call injection method here

    return 0;
}