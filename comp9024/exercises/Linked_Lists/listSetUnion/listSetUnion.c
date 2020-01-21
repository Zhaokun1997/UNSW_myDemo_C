
#include "list.h"

List listSetUnion(List s1, List s2)
{
    if (s1->head == NULL && s2->head == NULL)
    {
        return s1;
    } else if (s1->head == NULL && s2->head != NULL)
    {
        return s2;
    } else if (s1->head != NULL && s2->head == NULL)
    {
        return s1;
    } else
    {
        List s3 = newList();
        Node temp1 = s1->head;
        Node temp2 = s2->head;
        while (temp1 != NULL && temp2 != NULL)
        {
            /* code */
        }

        return s3;
    }
}
