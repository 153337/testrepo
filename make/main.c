#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gene_data.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// ���� �ּҰ��� �ָ� ��带 �����ϰ� ����� ���� �ּҸ� �����Ѵ�. 
// ����ü ����� ����Ѵ�. 

////////////////////////////  ����κ� 
int main() 
{
	
	unsigned int counter_main; // �¾��� ī���� 
	
	// ����ü ���� 
	memory_struct org; 
	plate table;
	gene_header temp;
	empty_pointer current_pointer;
	int seed;// �õ� 
	
	time_t time_set; // �ð����� 

	srand( (unsigned)time(NULL) );  // ����ȯ 
	

	
	
	org.org_address = (memory_struct*)malloc(sizeof(memory_struct));
	org.plate_address = (plate*)malloc(sizeof(plate));
	
	
	// ���� �Ҵ� (���̺� �ʱ�ȭ)
	for(counter_main=0;counter_main<100;counter_main++)
	{
		
		org.plate_address->breed_space[counter_main] = (gene_header*)malloc(sizeof(gene_header)); // ���� �Ҵ� 
		
	
	}
	
	// ���� �Ҵ� (����ü ����)
	for(counter_main=0;counter_main<100;counter_main++)
	{
	
		gene_maker(org.plate_address->breed_space[counter_main] ,counter_main,1 ,counter_main); // �ش翰��ü�� ���� ��ü ����  ó�� ���� �����Ҵ� 
		
	}
	
	ui_main(org);
	
	
	
	// �¾����� 
	
	// ���α׷� ���� 
/////////////////////////////////////////////////////////////////////////////////////////////////	
	
}





