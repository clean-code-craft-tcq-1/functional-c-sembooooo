#include "FailureHandling.h"
#include <stdio.h>


char *Failuretype_str[Failuretype_TotalNumber] =
{
    "No Failure",
    "Out of Lower Range ",
    "Out of Higher Range"
};


void LogFailure(char *Identifier, Failuretype_t Failuretype)
{
        printf("%s - %s\n",
         Identifier,
         Failuretype_str[Failuretype]);
}
