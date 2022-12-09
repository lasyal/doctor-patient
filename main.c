#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int docCount = 0;
int patCount = 0;
int slot1Count = 0;
int slot2Count = 0;
int docId;
int donarCount = 0;

struct donar
{
    char name[20];
    char organ[10];
    char phone[10];
    /* data */
} don[50];

struct patient
{
    int serial;
    char name[100];
    char phone[12];
    char aadhar[12];
    char history[100];
    struct patient *next;
} pat[10];

struct doctor
{
    char mciid[5];
    char name[20];
    char special[5];
    struct patient *patients[10];
} doc[10];

struct slot1
{
    /* data */
    char *docname;
    char *patname;
} slot1[10];

struct slot2
{
    /* data */
    char *docname;
    char *patname;

} slot2[10];

void addDoc()
{
    printf("enter doc details\n enter doc name :  ");
    scanf("%s", doc[docCount].name);
    printf(" enter doc specialization :  ");
    scanf("%s", doc[docCount].special);
    printf(" enter doc MCIID :  ");
    scanf("%s", doc[docCount].mciid);
    printf(doc[docCount].mciid);
    printf("\nYour id to login is : %d", docCount);
    docCount++;
}

void addDonar()
{
    printf("enter donar details\n enter donar name :  ");
    scanf("%s", don[donarCount].name);
    printf(" enter organ to donate :  ");
    scanf("%s", don[donarCount].organ);
    printf(" enter donar contact :  ");
    scanf("%s", don[donarCount].phone);
    printf(don[donarCount].phone);

    donarCount++;
}

void Appoint()
{
    printf("                      *********Appointment Portal*********\n");

    printf("enter patient details\n enter pat name :   ");
    scanf("%s", pat[patCount].name);
    printf("\nenter patient aadhar  :  ");
    scanf("%s", pat[patCount].aadhar);
    printf("\nenter patient history :  ");
    scanf("%s", pat[patCount].history);
    printf(" enter patient phone :  ");
    scanf("%s", pat[patCount].phone);

    printf(pat[patCount].name);

    printf("\nAvalable slots : ");
    if (slot1Count < 10)
    {
        printf("\n1 : slot 1 (9am - 12 pm) -- > avilable slots (%d)", 10 - slot1Count);
    }
    if (slot2Count < 10)
    {
        printf("\n2 : slot 2 (6pm - 9 pm)-- > avilable slots (%d)", 10 - slot2Count);
    }
    int slot;
    scanf("%d", &slot);

    printf("\n\nAvailable Doctors\n");
    for (int i = 0; i < docCount; i++)
    {

        printf("%d : %s", i, doc[i].name);
        printf("(%s) \n", doc[i].special);
    }
    int k;
    printf("select doc : ");
    scanf("%d", &k);
    if (slot == 1)
    {
        slot1[slot1Count].docname = &doc[k].name;
        slot1[slot1Count].patname = &pat[patCount].name;
        printf(slot1[slot1Count].patname);
        slot1Count++;
        printf("\nslot1 booked successfully");
    }
    else if (slot == 2)
    {
        slot2[slot2Count].docname = &doc[k].name;
        slot2[slot2Count].patname = &pat[patCount].name;
        printf(slot2[slot2Count].patname);
        slot2Count++;
        printf("slot2 booked successfully");
    }
    patCount++;
}

int main()
{

    char query, query2;
    while (1)
    {
        printf("                      *********Main Menu*********\n");
    main_again:
        printf("1.I'm a Patient\n2.I'm the Doctor\n3.I'm a Admin\n\n");
        scanf(" %c", &query);
        if (query == '1')
        {
            while (1)
            {
                system("cls");
                printf("                      *********Patient's Menu*********\n");
                printf("1.Register and Place Appointment\n2.Back to main menu.\n\n");
                char appoint1;
            patient_again:
                scanf(" %c", &appoint1);
                if (appoint1 == '1')
                {
                    system("cls");
                    Appoint();
                }
                else if (appoint1 == '2')
                {
                    system("cls");
                    break;
                }
                else
                {
                    printf("Wrong Command!!!\n\n");
                    goto patient_again;
                }
            }
        }
        else if (query == '2')
        {

            system("cls");
            printf("                      *********Doctor's Menu*********\n");
            printf("1.Register doc\n2.login\n3.Back to main menu.\n\n");
            char appoint2;
        doc_again:
            scanf(" %c", &appoint2);
            if (appoint2 == '1')
            {
                system("cls");
                addDoc();
            }
            else if (appoint2 == '2')
            {
                system("cls");
                printf("Enter your ID (1-10)");
                scanf("%d", &docId);
                printf("List of your appointments\n");
                if (slot1 != NULL)
                {
                    printf("\nBookings in slot1\n");
                    for (int i = 0; i < slot1Count; i++)
                    {

                        if (slot1[i].docname == doc[docId].name)
                        {
                            printf("\n Name :");
                            printf(slot1[i].patname);
                            for (int j = 0; j < patCount; j++)
                            {
                                if (slot1[i].patname == pat[j].name)
                                {
                                    printf("\n Contact :");
                                    printf(pat[j].phone);
                                    printf("\n History :");
                                    printf(pat[j].history);
                                }
                                /* code */
                            }
                        }
                    }
                }
                if (slot2 != NULL)
                {
                    printf("\nBookings in slot2\n");
                    for (int i = 0; i < slot2Count; i++)
                    {

                        if (slot2[i].docname == doc[docId].name)
                        {
                            printf("\n Name :");
                            printf(slot2[i].patname);
                            for (int j = 0; j < patCount; j++)
                            {
                                if (slot2[i].patname == pat[j].name)
                                {
                                    printf("\n Contact :");
                                    printf(pat[j].phone);
                                    printf("\n History :");
                                    printf(pat[j].history);
                                }
                                /* code */
                            }
                        }
                    }
                }
            }

            else if (appoint2 == '3')
            {
                system("cls");
                break;
            }
            else
            {
                printf("Wrong Command!!!\n\n");
                goto doc_again;
            }
        }
        else if (query == '3')
        {
            system("cls");
            printf("                      *********Admin Menu*********\n");
            printf("1.Edit doc\n2.Register donar\n3.Show donars\n\n");
            char appoint2;
        admin_again:
            scanf(" %c", &appoint2);
            if (appoint2 == '1')
            {
                int tempid, opt;
                printf("Enter Doctor ID\n");
                scanf("%d", &tempid);
                printf(doc[tempid].name);
                printf("\n1.name\n2.specialization\n3.mccid\n\n");
                printf("Enter option to edit : ");
                scanf("%d", &opt);
                if (opt == 1)
                {
                    char newname[20];

                    printf("Enter Doctor New name\n");
                    scanf("%s", doc[tempid].name);
                    printf("\nName changed to : ");
                    printf(doc[tempid].name);
                }
                else if (opt == 2)
                {
                    printf("Enter Doctor New specialization\n");
                    scanf("%s", doc[tempid].special);
                    printf("\nSpecialization changed to : ");
                    printf(doc[tempid].special);
                }
                else if (opt == 3)
                {
                    printf("Enter Doctor New mccid\n");
                    scanf("%s", doc[tempid].mciid);
                    printf("\nMciid changed to : ");
                    printf(doc[tempid].mciid);
                }
            }
            else if (appoint2 == '2')
            {
                addDonar();
            }
            else if (appoint2 == '3')
            {
                for (int i = 0; i < donarCount; i++)
                {
                    printf("\n List of donars :\n");
                    printf(don[i].name);
                    printf("\n");
                    printf(don[i].organ);
                    printf("\n");
                    printf(don[i].phone);
                    printf("\n");
                }
            }
            else
            {
                printf("Wrong Command!!!\n\n");
                goto admin_again;
            }
        }
        else if (query2 == '4')
        {
            exit(0);
        }
        else
        {
            printf("Wrong Command!!!\n\n");
            goto main_again;
        }
    }
    return 0;
}