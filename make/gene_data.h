#include<time.h>
#include<stdio.h>
#include<stdlib.h>

#ifndef const_size // ��� ������ 
#define const_size

#define gene_node_length 256 // �� �������� ����  (16*16)/2 �̺κ��� �����ϸ� ��ü �������� ũ�⸦ �����Ҽ� �ִ�. 
#define space_width 16
#define space_height 16


#define succ_operation 1
#define fail_operation 0

#define Ture 1
#define False 0


#define memory_alloc 1
#define memory_unalloc 0
#define memory_alloc_fail 2
#define memory_unalloc_fail 3



#endif


#ifndef re_define
#define re_define

typedef unsigned int basic_data; // �⺻ �������� ����ȭ 
typedef void* empty_pointer ; // void *�� ����ȭ 


#endif



#ifndef gene_struct
#define gene_struct


typedef struct gene_body
{
	
	
	struct gene_body * prev_node;
	struct gene_body * curr_node;
	struct gene_body * next_node;
	struct gene_body * tail_node;
	
	unsigned char temper; // ���� 
	unsigned int node_num; // ���� ����� ��ȣ 
	
}gene_body;



typedef struct gene_header
{
	
	unsigned int seed; // �õ� �����̴� 
	unsigned int gene_num; // ���� ��ȣ�̴�. 
	struct gene_body * neck_node;// ��ü�� �Ӹ��� �̾��ش�.  
	
}gene_header;



typedef struct plate
{
	
	unsigned int generation_num; //
	struct gene_header* breed_space[100]; // �Ӹ�(������)�� ��ġ�� ���� �迭 
	char plate_neme[256]; // ���̺� �̸� 
	
}plate; // ���� ���̺� 


#endif


#ifndef memory_struct_and_func
#define memory_struct_and_func

struct gene_body * gene_maker(struct gene_header * head ,int num,int init ,int ui); // �¾� ���� 
struct gene_body * gene_modifer(struct gene_header * head ,int num); // ����ü �������� 
struct gene_body * gene_eraser(struct gene_header * head ,int num, int value) ; // ���������� �ʱ�ȭ 

unsigned int return_memory_allocation(unsigned int option, void * pointer_target);




typedef struct memory_struct
{
	struct memory_struct * org_address;// ����� �޸𸮰����� �����ּҰ� ����. 
	struct plate *plate_address;// ����� �޸𸮰�����  ���̺� �ּҰ� ����. 
	
}memory_struct;

typedef struct pointer_carrier_box // ����ִ� ������ �ڽ� 
{
	struct pointer_carrier_box * box_address;// �ڽ��� �ּ� 
	empty_pointer obj_address; // �ڽ��� ����Ű�� �ּ� 
	
}pointer_carrier_box;

typedef struct swap_area // ���� ����ü 
{
	struct swap_area * swap_store_address;// ���� ����ü�� �ּ� 
	empty_pointer org_address; // ���� ����� �ּ� 
	empty_pointer dest_address;// ���� ���2�� �ּ�
	unsigned int content_size; // // ���� ����� ũ�� 
	
}swap_area;

gene_body * gene_maker(gene_header * head ,int num,int init,int ui ) // �����ڸ� �����ϴ� �ӽ��Լ�  (�޸��Լ� ������Ÿ��)
{
	
	
	
	int counter=0;
	unsigned int pos[gene_node_length];	

	// start-> ���� ���� �ּ� 
	gene_body * start;
	gene_body * next;
	
	for(counter=0;counter<gene_node_length;counter ++)
	{
		pos[counter]=0;
	}
	counter=0;
	if(init == Ture)// ���������ΰ�? 
	head->neck_node = ( gene_body*)malloc(sizeof(gene_body));
	else
	{
		
	}
	
	start = head->neck_node;
	

	
	while(1)
	{
		if(counter>gene_node_length-1)// ������ ������ �Ѿ��°�? 
		break;
		
		
		
		if(init == Ture)
		{// ���������ΰ�? 
		
			while(1)
			{
				start->temper = rand()%(gene_node_length+1);
				if(pos[start->temper] == 0)
				{
					pos[start->temper] = 1;
					
					
					break;
				}
				
				
			}	
		
			
			
			
		}	
		else
		{
			// ��ü�� ������ �޾ƿ� 
		}
		
		
		start->node_num = counter; // ��� ��ȣ 
		start->curr_node = start; // ���� ��� �ּ� 
		next = ( gene_body* )malloc(sizeof(gene_body)); // ���� ��� �ּ� (���ϵ�) 
		start->next_node = next;
		start->next_node->prev_node = start; // ���� �ּ��� ���� ����� ���� �����ʹ� ���� �����ּ� 
		start = next;
		counter++;
	}
	
	if(num < 80)
	{
		printf("|",counter);
		usleep(50000);
	}
	
}
 

struct gene_body * gene_modifer(struct gene_header * head ,int num)
{
	
	head->neck_node;
	
}

struct gene_body * gene_eraser(struct gene_header * head ,int num, int value) 
{
	
}

unsigned int return_memory_allocation(unsigned int option, void * pointer_target)
{
	
	free(pointer_target);
	return 0;
	
}






#endif



#ifndef omok_space_struct
#define omok_space_struct

unsigned int referee();


typedef struct omok_space
{
	unsigned char space[space_width][space_height]; // ���ΰ���  (�ð� ������)
	unsigned int space_stat;// ������ ������� 
	
	
}omok_space;


char *all_line; // 2���� �迭�� 1���� �迭���� ���ߴ� ���� 

unsigned int referee()
{
	
}





#endif




#ifndef api
#define api

unsigned int show(unsigned int start_pos ,unsigned int dest_pos, gene_header** read_address); //���� ������� ���� �Լ� 
unsigned int ui_main(memory_struct  current_pos); // ui���� 
unsigned int space_view(gene_header** read_address);





unsigned int show(unsigned int start_pos ,unsigned int dest_pos, gene_header** read_address)
{
	
	gene_body* start;
	unsigned int counter;
	unsigned int counter2;
	
	unsigned char x,y;
	
	
	for(counter = start_pos ;counter <= dest_pos;counter++  )
	{
		
		start = read_address[counter]->neck_node;
 		printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤ� %d \n", counter);
		for(counter2=0;counter2<gene_node_length;counter2++)
		{
			
			printf("%d �� ���  \n", start->node_num );
		
			y= start->temper << 4;
			y= y >> 4;
			
			x= start->temper >> 4;
			
			printf("x: %d y:  %d \n", x,y );
			
			
			if(start->next_node == NULL)
			{
				return 0;
			} 
			
			start = start->next_node;
		}
			
	}
	
	
	
}



unsigned int ui_main(memory_struct  current_pos)
{
	void* current_pointer;
	
	current_pointer = current_pos.plate_address->breed_space; // ���� �ּҸ� �Ѱ� ���� ��Ʈ 
	 
	unsigned int select1 , select2; 
	unsigned int choose;
	
	while(1)
	{
		printf("���� ���� �˰��� 153337 �����\n");
		printf("\n \t 1.����ü ��ġ������  ���� \n");
		printf("\n \t 2.����ü ��ǥ�󿡼� ���� \n");
		printf("\n \t 3.ȯ�� ���� \n");
		
		scanf("%d",&choose);
		fflush(stdin);
		if(choose == 1) // ������ ���� 
		{
			while(1)
			{
				printf("�ΰ��� ���� �Է��ϼ��� �� ����  ���ų� ������ �ʰ��Ǹ� �����\n");
				scanf("%d",&select1);
				fflush(stdin);
				scanf("%d",&select2);
				fflush(stdin);
				
				if(select1 == select2)
				{
					break;
				}
				if(select1 >= 100 || select2 >= 100 || select1 <= 0 || select2 <= 0)
				{
					break;
				}
				
				show(select1,select2,current_pointer); // ����ü ���� ��� 
			}
		} 
		else if(choose == 2)// ���� ���� 
		{
			space_view(current_pointer);
		}
		else if(choose == 3)// ��ǥ ���� �˻� 
		{
			
		}
		else
		{
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		
	} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}

unsigned int space_view(gene_header** read_address)
{
	
	omok_space space;
	unsigned int counter_x,counter_y;
	gene_body* start;
	unsigned int counter_gene_head;
	unsigned int counter2;
	unsigned char x,y;
	
	
	for(counter_x = 0 ;counter_x < space_height; counter_x++)
	{
		for(counter_y = 0 ;counter_y < space_width; counter_y++)
		{
			space.space[counter_x][counter_y] = 0;
		}
		
	}
	// ��ǥ�ʱ�ȭ ��� 
	
	while(1)
	{
		printf("����ü ��ȣ�� �Է��ϼ���\n");
		scanf("%d",&counter_gene_head);
		
		
		if(counter_gene_head >= 100)
		break;

		start = read_address[counter_gene_head]->neck_node;
 
		for(counter2=0;counter2<gene_node_length;counter2++)
		{
			
			
		
			y= start->temper << 4;
			y= y >> 4;
			
			x= start->temper >> 4;
			
			
			space.space[x][y] = 1;
			
			
			
			if(start->next_node == NULL)
			{
				return 0;
			} 
			
			
			for(counter_x = 0 ;counter_x < space_height; counter_x++)
			{
				printf("\n");
				for(counter_y = 0 ;counter_y < space_width; counter_y++)
				{
					printf("%d ",space.space[counter_x][counter_y]);
				}
				
			}
			printf("\n");-
			system("pause");
			system("cls");
			
			
			
			start = start->next_node;
		}
			
			
			
		
		

	}
	
	
	
	
	
	
	
}


#endif


