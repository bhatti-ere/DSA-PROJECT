#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <climits>
#include <stdexcept>
using namespace std;

//menu class
class Menu
{
public:
    string name;
    double price;
    Menu(string name, double price) : name(name), price(price)
	{}
};

//node 
class ListNode
{
	public:
		Menu item;
		ListNode* next;
    	ListNode(Menu item):item(item),next(NULL)
    	{}
};

// to manage menu
class LinkedList
{
	private:
		ListNode* head;
	public:
		LinkedList()
		{
		head=NULL;
		}
void addItem(Menu item)
{
	ListNode* newNode=new ListNode(item);
	newNode->item=item;
	if(!head)
	{
	head=newNode;
	}
	else
	{
	ListNode* temp=head;
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	temp->next=newNode;
	}
}

void displayMenu()
{
cout << "----------------------------"<<endl;
        cout<<"    Hot & Spicy Restaurant "<<endl;

        cout<<"           Menu             " <<endl;

cout<<"----------------------------"<<endl;

cout<<"Item                      Price (PKR)"<<endl;

cout << "----------------------------" << endl;

ListNode* temp=head;
int index=1;
while(temp)
{
	cout<<index<<". "<<temp->item.name;
    for(int i = temp->item.name.length();i<25;++i)
	{
	cout<<" ";
	}
	cout<<temp->item.price<<endl;
	temp=temp->next;
	index++;
}
    //spacing
cout<<"----------------------------"<<endl;
cout<<endl; 
}

Menu getItem(int index)
{
	ListNode* temp=head;
	int count=1;

	while(temp &&count<index)
{
	temp=temp->next;
	count++;
}

	if(temp)
{
	return temp->item;
}

	else
{
	cout<<"Invalid index";
}
}

int getSize() 
{
	int size=0;
	
	ListNode* temp=head;
	
	while (temp)
{
	size++;

	temp=temp->next;
}

return size;
}
};

//queues are used to place order
//implementation of queues using linked list
class Order
{	
	private:
	ListNode* order;
	double total;

	public:
	Order()
{
	order=NULL;  
	total=0.0;   

}

void addItem(Menu item)
{

	ListNode* newNode = new ListNode(item);

	newNode->item=item;      

	if (!order)
{
	order=newNode;
}
	else
{
	ListNode* temp=order;

	while(temp->next)
{
	temp=temp->next;
}

	temp->next=newNode;
}
	total+=item.price;
}

void displayOrder() 
{
cout<<"----------------------------"<<endl;

cout<< "         Your Order         "<<endl;

cout<<"----------------------------"<<endl;
cout<<"Item                      Price (PKR)"<<endl;

cout<<"----------------------------"<<endl;
ListNode* temp=order;

	while(temp)
{
	cout<<temp->item.name;

	for(int i=temp->item.name.length();i<25;++i)
{
	cout << " ";
}
	cout<<temp->item.price<<endl;

	temp=temp->next;
}
cout<<"----------------------------"<<endl;

cout<<"Total                     " <<total<<endl;

cout<<"----------------------------"<<endl;
        cout << endl; 
    }

    double getTotal() const
	
{
        return total;
}

};

//class for the order queue
class OrderQueue

{
	private:
	queue<Order>orders;

	public:

void addOrder(Order order)
{
	orders.push(order);
}

	Order processOrder()
{

	if(!orders.empty())
{

	Order order=orders.front();
    
	orders.pop();

	return order;
}
	else
{
	cout<<"No orders to process."<<endl;

	return Order(); // retrun empty order

}

}
		bool isEmpty()
{
	return orders.empty();//
}

};




// Graph class for rider(delivery route)
class abdullah
{
private:
    map<int,map<int,int> > adjmat;
    int TV;
    map<string,int>placeIndices; 

public:
    abdullah(int vtx):TV(vtx) {
    for(int i=0;i<TV;i++)
	{
        map<int,int>Barira;
    for(int j=0;j<TV;j++)
	{
        Barira[j]=INT_MAX;
}

adjmat[i]=Barira;

}

}

void twoside(int start,int end,int weight)

{
adjmat[end][start]=weight;

adjmat[start][end]=weight;

}

vector<int>Djstra(int src,int dest,int& shortcut)

{

	vector<int>dist(TV,INT_MAX);
	vector<bool>visited(TV,false);
	vector<int> previous(TV,-1);
	dist[src]=0;

 	for(int count=0;count<TV-1;count++)
 {
	
	int u=minDistance(dist,visited);

	visited[u] =true;

	for (int v=0;v<TV;v++)
	
{
    if(!visited[v]&&adjmat[u][v]!=INT_MAX&&dist[u]!=INT_MAX&&dist[u]+adjmat[u][v]<dist[v])
				
{
	dist[v]=dist[u]+adjmat[u][v];
	previous[v]=u;
}

}

}

	shortcut=dist[dest];

	vector<int>path;

	int y=dest;

	while (y!=-1)
{

	path.insert(path.begin(), y);

	y=previous[y];
	
}

	return path;
}

	int minDistance(const vector<int>& dist,const vector<bool>& visited)

{
 
int min=INT_MAX,minnindx;

	for(int v=0;v<TV;v++)
{

	if(!visited[v]&&dist[v]<= min)
{

	min=dist[v];
	minnindx = v;

}

}
 
	return minnindx;

}

void addplaceName(string placeName,int index)
  
{

	placeIndices[placeName]=index;

}

int getIndexFromName(string placeName)

{

	return placeIndices[placeName];

}
    
	string getNameFromIndex(int index)

{
 string names[52] = {"DHA1", "BahriaTown7", "BahriaTown8", "Morgah" ,"ChaklalaScheme3" ,"Saddar" , "Gulrez 2" , 
                     "British Homes" , "Westridge 1" , "LiaquatBagh" , "Askari 14" , "Bostan valley" , "CommitteeChowk" , 
					 "BakraMandi" , "Gulistan Colony" , "MediaTown" , "Askari 2" , "Lane5 PR" "Lane4 PR" , "Lane6 PR" ,
					 "RangeRoad" ,"Misrial Road", "BahriaTown3" , "Lalazar" , "Parade Lane" , "Yousuf Colony","Askari 11" , 
					 "Cobb Lines" , "Dhoke Banaras Road" , "Afshan Colony" , "Peoples colony" , "Abid Majeed Road" , "Tench Bhatta" ,
					 "Railway colony" , "Azizabad" , "laalKurti" , "Dhoke Syedan","Raja Bazaar", "Muslim Town","Convoy Road",
					 "Golra Mor","Nust EME","CMH"  "MH" , "Harley street" , "Civil Lines", "Allama Iqbal Colony" , "ShalleyValley" ,
					  "RattaAmral" ,"Westridge 3" , "Ghaziabad" , "Westridge 2" };
        if(index>=0 &&index<52)
		
{
    return names[index];
}
        return "Invalid place Index";
}
};

class Review {
public:
    int rating;
    string reviewText;

    Review(int r, string text) : rating(r), reviewText(text) {}
};

class TreeNode {
public:
    Review data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Review review) : data(review), left(NULL), right(NULL) {}
};

class BST {
private:
    TreeNode* root;

    void insertHelper(TreeNode*& node, Review review) {
        if (node == NULL) {
            node = new TreeNode(review);
        } else if (review.rating < node->data.rating) {
            insertHelper(node->left, review);
        } else {
            insertHelper(node->right, review);
        }
    }

    void inOrderTraversalHelper(TreeNode* node)  {
        if (node != NULL) {
            inOrderTraversalHelper(node->left);
            cout << "Rating: " << node->data.rating << ", Review: " << node->data.reviewText << endl;
            inOrderTraversalHelper(node->right);
        }
    }
public:
    BST() : root(NULL) {}

    void insert(Review review) {
        insertHelper(root, review);
    }

    void displayInOrder()  {
        inOrderTraversalHelper(root);
        cout << "----------------------------" << endl;
    }
};


//-------------------------------------------------------------------
int main() {
	
  ifstream abdul("CHANGESECreT.txt"); 
    if (!abdul) 
	{
        cout << "File nahi khuli." << endl;
        return 1;
    }
    cout<<"*****************************************************************************************"<<endl;
    cout << "THE CODE IS CASE SENSITIVE PLEASE KEEP THIS IN MIND " << endl << endl;
    cout<<"*****************************************************************************************"<<endl;

    // MENU
    LinkedList menu;
    menu.addItem(Menu("MUTTON KARAHI HALF KG", 2000.00));
    menu.addItem(Menu("CHICKEN Karahi HALF ", 1200.00));
    menu.addItem(Menu("Nihari", 300.00));
    menu.addItem(Menu("Haleem", 250.00));
    menu.addItem(Menu("Chapli Kebab", 150.00));
    menu.addItem(Menu("chicken malai boti", 300.00));
    menu.addItem(Menu("chicken tikka", 300.00));
    menu.addItem(Menu("afghani pulao", 300.00));
    menu.addItem(Menu("biryani", 300.00));
    menu.addItem(Menu("Roti", 10.00));
    menu.addItem(Menu("Naan", 20.00));
    menu.addItem(Menu("Chai", 50.00));
    menu.addItem(Menu("Lassi", 80.00));
    

    // ORDER QUEUE
    OrderQueue orderQueue;

    // Place  YOUR Orders
    char choice;
    do {
        Order order;
        char orderChoice;
        int itemNumber;
        menu.displayMenu();
        do 
		{
    
            cout << "Enter the item number to add to your order (1-" << menu.getSize() << "): ";
            cin >> itemNumber;
            try 
			{
                if (itemNumber > 0 && itemNumber <= menu.getSize())
				 {
                    order.addItem(menu.getItem(itemNumber));
                    cout << menu.getItem(itemNumber).name << " added to your order." << endl;
                }
				else 
				{
                    cout << "Invalid item number. Please try again." << endl;
                }
            } 
            catch (const out_of_range& e)
			{
			
                cout << "Invalid item number. Please try again." << endl;
            }
            cout<< "Do you want to add another item to your order? (y/n): ";
            cin >> orderChoice;
        } 
		while (orderChoice == 'y' || orderChoice == 'y' );

        orderQueue.addOrder(order);

        cout << "Do you want to place another order? (y/n): ";
        cin >> choice;
    } 
	while (choice == 'y' || choice == 'y');
	
    // Process Orders
    while (!orderQueue.isEmpty()) 
	{
        Order processedOrder = orderQueue.processOrder();
        processedOrder.displayOrder();
    }

    //  Graph for Delivery Routing
    cout<<"|_____________________________________________________________________________________|\n"<<endl;
    cout<<"THE PLACES WE DELIVER TO ARE AS FOLLOWED: \n"<<endl; 
	cout<<"\n DHA1 ,  BahriaTown7, BahriaTown8  , Morgah ,  ChaklalaScheme3 , Saddar ,Gulrez 2, \n"<<endl;
	cout<<"\n British Homes , Westridge 1 ,LiaquatBagh ,Askari 14 ,Bostan valley,CommitteeChowk, \n"<<endl;
	cout<<"\n BakraMandi , Gulistan Colony , MediaTown , Askari 2 , Lane5 PR ,Lane4 PR , Lane6 PR,\n "<<endl;
	cout<<"\n RangeRoad , BahriaTown3 , Lalazar , Yousuf Colony ,Parade Lane ,Askari 11,Cobb Lines\n"<<endl;
	cout<<"\n Dhoke Banaras Road , Afshan Colony , Peoples colony , Abid Majeed Road , Tench Bhatta\n"<<endl;
	cout<<"\n Railway colony , Azizabad , laalKurti , Dhoke Syedan ,Raja Bazaar,Muslim Town,Raja Bazaar \n"<<endl;
	cout<<"\n Muslim Town , Convoy Road , Golra Mor , Nust EME , CMH , MH , Harley street , Civil Lines \n"<<endl;
	cout<<"\n Allama Iqbal Colony , ShalleyValley , RattaAmral , Westridge 3 , Ghaziabad , Westridge 2 \n"<<endl;
    cout<<"|_____________________________________________________________________________________|"<<endl;
  
  int TtlVrtx, start, end, weight;
    abdul >> TtlVrtx;
    abdullah graph(TtlVrtx);

    string line;
    getline(abdul, line);
    while (getline(abdul, line)) 
	{
        istringstream iss(line);
        iss >> start;
        while (iss >> end)
		{
            if (!(iss >> weight)) 
			{
                weight = end;
                end = -1;
            }
            
            graph.twoside(start, end, weight);
        }
    }
    abdul.close();

//int A;
  for(int A = 0;A<= 51; A++)
//	while(A<=51)
	{
        graph.addplaceName(graph.getNameFromIndex(A), A);
		
		//graph.addplaceName(graph.getNameFromIndex(A), A);
//A++;
    }
      cout<<"ok";

    string srcplace, dstplace;
    bool validStart = false;
    int attempts = 0;
          

    while (!validStart && attempts < 2) 
	{
        cout << "\nEnter the starting place name (DHA1 or Saddar): ";
        getline(cin >> ws, srcplace);
        if (srcplace == "DHA1" || srcplace == "Saddar") 
		{
            validStart = true;
        } 
		else 
			{
            attempts++;
            if (attempts < 2)
			{
                cout << "THE BRANCH DOES NOT EXIST HERE. PLEASE SELECT ANOTHER PLACE." << endl;
            }
			else
			{
                cout << "WRONG PLACE AGAIN BYE BYE." << endl;
                return 1;
            }
        }
    }
                                                                      
    cout << " Enter the Place where you want the order to be delivered: ";
    getline(cin >> ws, dstplace);

    int srcIndex = graph.getIndexFromName(srcplace);
    int dstIndex = graph.getIndexFromName(dstplace);

    if (srcIndex == -1 || dstIndex == -1) {
        cout << "Invalid place Name" << endl;
        return 1;
    }

    int shortcut;
    vector<int> path = graph.Djstra(srcIndex, dstIndex, shortcut);
    if (shortcut == INT_MAX) 
	{
        cout << "Sorry, no path found." << endl;
    } 
	else 
	{
        cout << " Shortest distance is: " << shortcut << "  KM" << endl;
        cout << " Path is: ";
        
		for (int i = 0; i < path.size(); i++)
		{
            cout << graph.getNameFromIndex(path[i]);
            if (i != path.size() - 1)
			{
                cout << " -------> ";
            }
        }
        cout << endl;
        cout << endl;
        float distance;
        distance=shortcut;
        cout<<"  The time for this delivery is: "<<((distance/40))*60 <<"                                                                       Minutes"<<endl;
        if (shortcut <= 10 )
        {
        	cout<<" The delivery charges are: 120 Rs"<<endl; 
		}
        else if (shortcut >= 10 && shortcut <= 20)
        {
        	
        	cout<<"  The delivery charges are : 220 Rs"<<endl;
		}
		else 
		{
			cout <<"  The delivery Charges are 300 Rs"<<endl;
		}
		cout<<"  --------------------------------------------"<<endl;
    }

BST bst;

    bst.insert(Review(5, "  Fast delivery and good food!"));
    bst.insert(Review(3, "  Late delivery but food was good."));
    bst.insert(Review(4, "  Timely delivered and good food."));
    bst.insert(Review(1, "  Poor services."));
    bst.insert(Review(2, "  Delivery was late, and also food was okay."));

    bst.displayInOrder();

    char addMore = 'y';

    while (addMore == 'y') {
        int rating;
        string reviewText;

        cout << "  Enter rating (1-5): ";
        cin >> rating;
        cout << "  Enter review: ";
        getline(cin >> ws, reviewText);

        bst.insert(Review(rating, reviewText));

        cout << "  Do you want to add another review? (y/n): ";
        cin >> addMore;
    }
     cout<<"                             Thank you";
     
   

    return 0;
}


