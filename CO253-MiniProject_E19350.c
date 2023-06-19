#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100  //defining the maximum number of contacts that can memorize

struct contact {  //creating "contact" structure 
    char name[50];
    char number[20];
    char address[100];
    char email[100];
};

struct contact contacts[MAX_CONTACTS]; //declares an array of "contact" structures named "contacts"
int num_contacts = 0;

//function to add a new contact
void add_contact() {
    struct contact new_contact;

    if(num_contacts == MAX_CONTACTS){

        system("clear");  //clear the screen before next step
        printf("\n\n\nSystem Memory is full!!!");
        printf("\nIf you want to add more contact,You have to delete some contact from your list...\n\n\n");
        return;

    }else{

        //getting information for the new contact
        printf("Contact Name  : ");
        getchar();
        scanf("%[^\n]s", new_contact.name);

        printf("\nPhone Number  : ");
        scanf("%s", new_contact.number);

        printf("\nAddress       : ");
        getchar();
        scanf("%[^\n]s", new_contact.address);

        printf("\nEmail Address : ");
        scanf("%s", new_contact.email);

        contacts[num_contacts++] = new_contact;

        system("clear");
        printf("\t\nContact Saved...\n\n\n\n");
    }
}

//function to search for a contact
void search_contact() {
    char keyword[40];

    printf("Enter the contact name or phone number to search for: ");
    getchar();
    scanf("%[^\n]s", keyword);
    system("clear");

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, keyword) == 0 || strcmp(contacts[i].number, keyword) == 0 ) {  //checking whether the name or number of the contact matches the keyword
            printf("Contact found:\n\n");
            printf("\tName         : %s\n", contacts[i].name);
            printf("\tPhone Number : %s\n", contacts[i].number);
            printf("\tAddress      : %s\n", contacts[i].address);
            printf("\tEmail        : %s\n\n\n", contacts[i].email);
            return;
        }
    }
    printf("\nContact not found...\n\n");
}

//function to show all contacts
void show_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("Contact %d:\n", i + 1);
        printf("\tName         : %s\n", contacts[i].name);
        printf("\tPhone Number : %s\n", contacts[i].number);
        printf("\tAddress      : %s\n", contacts[i].address);
        printf("\tEmail        : %s\n\n\n", contacts[i].email);
    }
}

//function to edit a contact
void edit_contact() {
    char keyword[40];

    printf("Enter the contact name or phone number to edit: ");
    getchar();
    scanf("%[^\n]s", keyword);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, keyword) == 0 || strcmp(contacts[i].number, keyword) == 0 ) {
            
            printf("\nContact %d:\n", i + 1);
            printf("\tName         : %s\n", contacts[i].name);
            printf("\tPhone Number : %s\n", contacts[i].number);
            printf("\tAddress      : %s\n", contacts[i].address);
            printf("\tEmail        : %s\n\n\n", contacts[i].email);
            
            printf("\n\nNew contact name : ");
            getchar();
            scanf("%[^\n]s", contacts[i].name);

            printf("\nNew phone number   : ");
            scanf("%s", contacts[i].number);

            printf("\nNew address        : ");
            getchar();
            scanf("%[^\n]s", contacts[i].address);

            printf("\nNew Email address  : ");
            scanf("%s", contacts[i].email);

            system("clear");
            printf("\nContact Updated...\n\n");

            return;
        }
    }
    printf("\nContact not found...\n\n");
}

//function to delete a contact
void delete_contact() {
    char keyword[40];
    char confirm;

    printf("Enter the contact name or phone number to delete: ");
    getchar();
    scanf("%[^\n]s", keyword);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, keyword) == 0 || strcmp(contacts[i].number, keyword) == 0) {

            system("clear");
            printf("Are you sure you want to delete the contact ?");
            printf("\n\nContact %d:\n", i + 1);
            printf("\tName         : %s\n", contacts[i].name);
            printf("\tPhone Number : %s\n", contacts[i].number);
            printf("\tAddress      : %s\n", contacts[i].address);
            printf("\tEmail        : %s\n\n\n", contacts[i].email);
            printf("Type 'Y' to continue or 'N' to go back  : ");
            getchar();
            scanf("%c", &confirm);

            //selection to confirm the deleting process
            if (confirm == 'Y' || confirm == 'y'){

                for (int j = i; j < num_contacts - 1; j++) {
                    contacts[j] = contacts[j + 1];  //shifting contacts to the left, for overwrite the contact to be deleted
                }

                num_contacts--;

                system("clear");
                printf("\nContact Deleted...\n\n");

                return;

            }else if (confirm == 'N' || confirm == 'n'){
                system("clear");
                return;

            }else{
                system("clear");
                printf("Invalid Answer...\n");
                return;
            }
        }
    }
    system("clear");
    printf("\nContact not found...\n");
}

//function to delete all contacts at once
void delete_all_contacts() {

    char confirm;

    system("clear");
    printf("Are you sure you want to delete all contacts ?\n\n");
    printf("Type 'Y' to continue or 'N' to go back  : ");
    getchar();
    scanf("%c", &confirm);

    if (confirm == 'Y' || confirm == 'y'){
  
        for (int j = 0; j <= num_contacts; j++) {
            contacts[j] = contacts[j+1];
        }

        num_contacts = 0;

        system("clear");
        printf("\nAll Contacts Deleted...\n\n");

        return;

    }else if (confirm == 'N' || confirm == 'n'){
        system("clear");
        return;

    }else{
        system("clear");
        printf("Invalid Answer...");
        return;
    }
}

//function to export contacts to "contacts.txt" file
void exportContactsToFile(const char*) {
    FILE* file = fopen("contacts.txt", "w");  //open "contacts.txt" file for writing
    
    //if the file opening operation fails, printing an error
    if (file == NULL) {
        printf("Error Opening File.\n");
        return;
    }
    
    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "Contact %d:\n\tName         : %s\n\tPhone Number : %s\n\tAddress      : %s\n\tEmail        : %s\n\n\n", i+1, contacts[i].name, contacts[i].number, contacts[i].address, contacts[i].email);
    }
    
    fclose(file);
    printf("\nContacts Exported to 'contacts.txt' Successfully.\n\n");
}

int main() {
    int choice;

    while (1) {

        //creating the UI
        printf("------------------------------------------------------------");
        printf("\n\t\tContact Management System\n");
        printf("------------------------------------------------------------\n\n\n");
        printf("0. Quit\n\n");
        printf("1. Add new contact\n\n");
        printf("2. List all contacts\n\n");
        printf("3. Search for contact\n\n");
        printf("4. Edit contact\n\n");
        printf("5. Delete contact\n\n");
        printf("6. Delete all contacts\n\n");
        printf("7. Export contacts to a file\n\n");
        printf("------------------------------------------------------------");
        printf("\n\nEnter your choice [0 - 7] : ");  //getting users choice
        scanf("%d", &choice);

        if (choice == 0){
            break;
        }else{

            switch (choice) {
            case 1:
                system("clear");
                add_contact();
                break;
            case 2:
                system("clear");
                show_contacts();
                break;
            case 3:
                system("clear");
                search_contact();
                break;
            case 4:
                system("clear");
                edit_contact();
                break;
            case 5:
                system("clear");
                delete_contact();
                break;
            case 6:
                system("clear");
                delete_all_contacts();
                break;
            case 7:
                system("clear");
                exportContactsToFile("contacts.txt");
                break;
            default:
                system("clear");
                printf("\nInvalid choice...\n\n");
                break;
            }
        }
    }
}