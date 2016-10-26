#include "palindrom.h"
bool IsPalindrom(CNode* list)
{
	if (list==0)
		return true;
	CNode *tmp=list;
	int k=0;
	while (tmp!=0)
	{
		k++;
		tmp=tmp->next;
	}
	if (k==1)
		return true;
	int *a=new int[k/2];
	tmp=list;
	for(int i=0; i<k/2; ++i)
	{
		a[i]=tmp->data;
		tmp=tmp->next;
	}
	if (k%2==1)
		tmp=tmp->next;
    for(int i=k/2-1; i>=0; --i)
	{
		if (a[i]!=tmp->data)
			return false;
		tmp=tmp->next;
	}
	return true;
}

