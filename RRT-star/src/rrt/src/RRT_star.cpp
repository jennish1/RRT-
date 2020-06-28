// #include<iostream>
// #include<vector>
// #include<stdlib.h>
// #include<time.h>
// #include<math.h>
// #include "ros/ros.h"
//  #include "std_msgs/Header.h"
// #include "geometry_msgs/Pose.h"
// #include "nav_msgs/MapMetaData.h"
// #include "nav_msgs/OccupancyGrid.h"
// #include "nav_msgs/Path.h"
// // #include <typeinfo>
// using namespace std;


// float stepsize= 1;
// float radius= 7 ;
// float goal_radius= 1;

// float arr[2][4]= {{20, 50, 20, 50}, {50, 80, 50, 80}};
// int s= sizeof(arr)/sizeof(arr[0]);


// struct Point
// {
// 	double x;
// 	double y;
// };

// struct Node
// {

// 	float cost;
// 	Point P; 
// 	Node *parent;

// };

// const int goalx = 95;
// const int goaly = 95;
// const int begx = 1;
// const int begy = 1;

// const int gridx = 100;
// const int gridy = 100;

// Point gridSize = {gridx, gridy};

// Point goal= {goalx, goaly};
// Point beg= {begx, begy};

// // int arr_1[int(goal.x-beg.x)+1][int(goal.y-beg.y)+1];
// // int arr_1[gridx][gridy];
// // int arr_2[(goaly-begy)][gridy];


// Point x_centre= {(goal.x+beg.x)/2, (goal.y+beg.y)/2};


// float c_min= sqrt((goal.x-beg.x)*(goal.x-beg.x) + (goal.y-beg.y)*(goal.y-beg.y));
// float C[2][2]= {{(goal.x-beg.x)/c_min, (goal.x-beg.x)/c_min}, {(goal.y-beg.y)/c_min, (goal.y-beg.y)/c_min}} ;


// class RRT
// {
// public:
// 	Node* start = new Node;
// 	// start = &dd;
// 	vector<Node*> all_nodes;
// 	Node* final = new Node;
// 	Node sstart;
// 	RRT()
// 	{
		
		
// 		//cout<<"aa "<<(*start).P.x<<endl;
// 		//cout<<start->P.x<<endl;
		
// 		//cout<<sstart.P.x<<endl;
// 		(*start).P.x = beg.x;
		
// 		(*start).P.y = beg.y;
		
// 		start->parent= NULL;
		
// 		start->cost= 0;
		
// 		all_nodes.push_back(start);
		
// 		final->parent= NULL;
		
// 	}
// 	Node* generate_randnode()
// 	{
// 		Point p= {(rand() % int(gridSize.x+1)) + 1, ((rand() % int(gridSize.y+1)) + 1)};
// 		bool a= true;
// 		/*cout<<"sssssss"<<endl;
// 		for(int i= 0; i< all_nodes.size(); i++)
// 		{
// 			//cout<<"sssssss"<<endl;
// 			if(((p.x= (all_nodes[i]->P).x) && (p.y= (all_nodes[i]->P).y)))
// 				a= false;
				
// 		}*/
// 		if(a)
// 		{
// 			Node* rand_node= new Node;
// 			rand_node-> P= p;
// 			rand_node-> parent= NULL;
// 			return rand_node;
// 		}
// 		else
// 			generate_randnode();
// 	}
		


// 	/*float** multiply_matrices(float a[2][2], float b[2][2])
// 	{
// 		// float** c;
// 		float** c= new float*[2];
// 		c[0]= new float[2];
// 		c[1]= new float[2];
// 		c[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
// 		c[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];
// 		c[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
// 		c[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
// 		return c;
// 	}

// 	float* multiply_matr_vec(float a[2][2], float b[2])
// 	{
// 		float c_1[2];
// 		c_1[0]= a[0][0]*b[0] + a[0][1]*b[1];
// 		c_1[1]= a[1][0]*b[0] + a[1][1]*b[1];
// 		return c_1;
// 	}


// 	Node* sample(float c_best)
// 	{
// 		float r= (float) rand()/RAND_MAX;
// 		float theta= (float) rand()/RAND_MAX* 2*22/7;
// 		float s_1[2];
// 		s_1[0]= r*cos(theta);
// 		s_1[1]= r*sin(theta);
// 		float L[2][2]= {{0,0}, {0,0}};
// 		L[0][0]= c_best/2;
// 		L[1][1]= 0.5*sqrt(c_best*c_best - c_min*c_min);
// 		float** k=multiply_matrices(C, L);
		
// 		float* p= multiply_matr_vec(&&k, s_1);
// 		Point n;
// 		n.x= p[0]+x_centre.x;
// 		n.y= p[1]+x_centre.y;

// 		Node* rand_1;
// 		rand_1->P= n;
// 		if((obstacle_check(rand_1)) && n.x<= gridSize.x && n.y<= gridSize.y)
// 		{
// 			rand_1->parent= NULL;
// 			return rand_1;
// 		}
// 		else
// 			sample(c_best);

// 	}*/

// 	vector<Node*> near_nodes(Node* N)
// 	{
// 		//cout<<12345<<endl;
// 		vector<Node*> nearby_nodes;
// 		int e=1;
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			if(distance(all_nodes[i]->P, N->P)< radius)
// 			{
// 				// cout<<"boom "<<all_nodes[i]->P.x<<" "<<all_nodes[i]->P.y<<endl;
// 				nearby_nodes.push_back(all_nodes[i]);
// 			}
// 			if(all_nodes[i]==N)
// 			{
// 				//cout<<i;
// 				e=i;
// 			}
// 		}
// 		//cout<<endl<<3<<endl;
// 		//nearby_nodes.erase(nearby_nodes.begin()+ e);
// 		//cout<<nearby_nodes.size()<<endl<<"11236432875260746597284343798247897432894890952"<<endl;
// 		return nearby_nodes;
// 	}


// 	bool obstacle_check(Node* N)
// 	{
// 		Point p= N->P;
// 		for(int i=0; i<s; i++)
// 		{
// 			if((p.x>=(arr[i][0])&&p.x<=(arr[i][1])) && (p.y>=(arr[i][2])&&p.y<=(arr[i][3])))
// 				return false;
// 		}
// 		return true;
// 	}

// 	// bool obstacle_check_1(Node* N)
// 	// {
// 	// 	Point p= N->P;
// 	// 	int a, b;
// 	// 	a= p.x;
// 	// 	b= p.y;
// 	// 	if(arr_1[a][b]==1)
// 	// 		return false;
// 	// 	return true;
// 	// }


// 	bool linejoin_check(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		Node* N_1= new Node;
// 		Node* N_2= new Node;
// 		Node* N_3= new Node;
// 		Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
// 		Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
// 		Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
// 		N_1->P= n_1;
// 		N_2->P= n_2;
// 		N_3->P= n_3;
// 		/*if(obstacle_check(N_1)!= obstacle_check_1(N_1))
// 		{
// 				cout<<"££££££££££££££££"<<endl;
// 				Point c= N_1->P;
// 				cout<<c.x<<","<<c.y<<endl;
// 		}*/
// 		if(!(obstacle_check(N_1)))
// 			return 0;
// 		// else if(!(obstacle_check(N_2)))
// 		// 	return 0;
// 		// else if(!(obstacle_check(N_3)))
// 		// 	return 0;
// 		else
// 			return 1;
// 	}


// 	Node* nearest_node(Node* N)
// 	{
// 		Node* nearest= new Node;
// 		float d= 1000000;
// 		float m;
// 		//vector<Node*> all_= near_nodes(N);

// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			m= distance(all_nodes[i]->P, N->P);
// 			if(m<d)
// 			{
// 				d= m;
// 				nearest= all_nodes[i];
// 			}	
// 		}
// 		return nearest;
// 	}


// 	Node* new_node(Node* nearest, Node* N)
// 	{
// 		Node* new_node= new Node;
// 		float s= stepsize;
// 		Point m;
// 		//cout<<distance(nearest->P, N->P)<<endl;
// 		if(distance(N->P, nearest->P)< s)
// 		{
// 			new_node->P= N->P;
// 			new_node->cost= nearest->cost+ distance(N->P, nearest->P);
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}
// 		else
// 		{
// 			m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
// 			m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 			new_node->P= m;
// 		}
// 		//cout<<nearest->P.x<<endl<<nearest->P.y<<endl;
// 		//cout<<"00000000000000"<<endl<<m.x<<endl<<m.y<<endl;
// 		int a= 1;
// 		//cout<<!obstacle_check(new_node, arr)<<endl;
// 		while(a && s> 0.01*stepsize)
// 		{
// 			/*if(obstacle_check(new_node)!= obstacle_check_1(new_node))
// 			{
// 				cout<<"@@@@@@@@@@@@@@@@@@"<<endl;
// 				Point c= new_node->P;
// 				cout<<c.x<<","<<c.y<<endl;
// 			}*/
// 			if(!obstacle_check(new_node))
// 			{
				

// 				(new_node->P).x= 0.9*(new_node->P).x+ 0.1*(nearest->P).x;
// 				(new_node->P).y= 0.9*(new_node->P).y+ 0.1*(nearest->P).y;
// 				s*= 0.9;   
// 				//cout<<new_node->P.x<<endl<<new_node->P.y<<endl<<endl;
// 			}
// 			else
// 			{
// 				a= 0;
// 				new_node->cost= nearest->cost+ s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}

// 		}	
// 		/*if(a==0)
// 		{
// 			new_node->cost= nearest->cost+ s;
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}*/

// 			//cout<<a<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
// 			return NULL;
		
// 	}


// 	float distance(Point a, Point b)
// 	{
// 		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
// 	}




// 	Node* best_parent(Node* N)
// 	{
// 		vector<Node*> q= near_nodes(N);
// 		//cout<<"6666666666"<<q.size()<<endl;
// 		Node* best= new Node;
// 		best->cost = 10000000;
// 		float best_cost = best->cost;
// 		float now_cost = best->cost;
// 		// cout<<"innnnnnnnnnnnnnn"<<endl;
// 		for(int i= 0; i<q.size(); i++)
// 		{
// 			//cout<<"cost"<<" "<<q[i]->cost<<endl;
// 			if(!(q[i]== N))
// 				//cout<<"shoot "<<q[i]->cost<<endl;
// 				//+ distance(q[i]->P, N->P)
// 				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
// 				if(now_cost < best_cost)
// 				{
// 					//cout<<"in here"<<q[i]->P.x<<" "<<q[i]->P.y<<" "<<linejoin_check(q[i], N)<<endl;
					
// 					if((linejoin_check(q[i], N)))
// 					{
// 						best= q[i];
// 						// cout<<"asdfghjkl"<<endl;
// 						best_cost = now_cost;
// 						// best->cost = best_cost;
// 					}
// 				}
// 		}
// 		// cout<<"fu"<<endl;
// 		if(!(q.size()==1))
// 		{
// 			// cout<<"in here"<<best->P.x<<" "<<best->P.y<<endl;
// 			// cout<<"8888888888888"<<endl;
// 			N->cost= best_cost;
// 			N->parent= best;
// 			return best;
// 		}
// 		else
// 		{
// 			// cout<<"1111111111111"<<endl;
// 			return N->parent;
// 		}	
// 	}

// 	void rewire(Node* N)
// 	{
// 		vector<Node*> w= near_nodes(N);
// 		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
// 			w.push_back(final);
// 		//cout<<w.size();
// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if(best_parent(N)== w[i])
// 			{
// 				w.erase(w.begin()+ i);
// 				break;
// 			}
			
// 		}
// 		//cout<<endl<<w.size();
// 		//cout<<"£££££££££££££££££££££££££££££££££££"<<endl;

// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost)
// 			{
// 				//cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
// 				if((linejoin_check(N, w[i])))
// 				{
// 					w[i]->parent= N;
// 					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
// 				}
// 			}
// 		}

// 	}

// 	bool goal_check(Node* N, Point goal)
// 	{
// 		if(distance(N->P, goal) < goal_radius)
// 		{
// 			final->parent= N;
// 			final->P= goal;
// 			final->cost= N->cost+ distance(N->P, goal);
// 			return true;
// 		}
// 		return false;
// 	}

// 	vector<Point> shortest_path(Node* start, Node* final)
// 	{
// 		vector<Point> path;
		
// 		Node* a= final;
// 		int i=1;
// 		//cout<<98765<<endl;
// 		//cout<<start->P.x<<endl;
// 			while(!(a->parent== NULL))
// 			{
// 				//cout<<i<<endl;

// 				path.push_back(a->P);
// 				//cout<<path.size()<<endl;
// 				if((a->parent==start))
// 					path.push_back(start->P);
// 				a= a->parent;
// 				/*if(i==2)
// 				{
// 					cout<<7<<endl<<a->P.x<<endl;
// 					cout<<1111<<endl<<(a->parent==NULL)<<endl;
// 				}
				
// 				if(i==3)
// 				{

// 					cout<<2222222222<<endl;
// 				}*/


				
// 				i++;
				
// 			}
			
// 			//path.push_back(start->P);
// 		return path;
// 	}


// };



// vector<Point> find_path()
// {
// 	//int n= 1;
// 	//cin >> n;
// 	//float arr[4];
// 	//arr[0]= 10;
// 	//arr[1]= 90;
// 	//arr[2]= 10;
// 	//arr[3]= 90;
// 	//cout<<"aaaaaaa"<<endl;

// 	//for(int i=0; i<(sizeof(arr))/32; i++)
// 	//{
// 		//for(int j=0; j<4; j++)
// 		//	cin>> arr[i][j];
// 	//}


// 	RRT rrt;	
// 	Point goal;
// 	int X, Y;
// 	X= 95;
// 	Y= 95;
// 	goal.x= X;
// 	goal.y= Y;
// 	bool c= 0;

// 	int iter_max= 5000;
// 	vector<Point> Path;
// 	vector<Point> random_nodes;
// 	Node* rand_n= new Node;
// 	Node* nearest_1= new Node;
// 	Node* new_n= new Node;

// 	//cout<<888<<endl<<rrt.start->parent<<endl;
// 	int check= 1;


// 	for(int i= 1; i<iter_max; i++)
// 	{
// 		//cout<<endl<<i<<endl;
// 		//if(c==1)
// 		//	rand_n= rrt.sample(rrt.final->cost);
// 		//else
// 			rand_n= rrt.generate_randnode();
// 		random_nodes.push_back(rand_n->P);
		
		
		
		
// 		nearest_1= rrt.nearest_node(rand_n);
// 		//if(i==4)
// 		//	cout<<"ssssssss"<<endl<<nearest_1->P.x<<endl<<rand_n->P.x<<endl;
// 		//cout<<7777<<endl;
// 		//cout<<rrt.all_nodes.size()<<endl;
		
		
// 		//cout<<new_n->P.y<<endl;
// 		//rrt.best_parent(new_n);
		
// 		//new_n->parent= b;
// 		//rrt.rewire(new_n);



		
		
// 		new_n= rrt.new_node(nearest_1, rand_n);
// 		//cout<<new_n<<endl;
// 		if(!(new_n==NULL))
// 		{
			

			

// 			if(check==1)
// 			{
// 				if(rrt.goal_check(new_n, goal))
// 					check=0;
// 			}
			

// 			c= !(rrt.final->parent== NULL);
// 			//cout<<c<<endl;

// 			if(c==1)
// 			{
// 				//cout<<i<<endl<<"555555555555555555555555555"<<endl;
// 				/*for(int i=0; i<rrt.all_nodes.size(); i++)
// 				 {
// 				 	cout<<rrt.all_nodes[i]->P.x <<endl;
// 				 	cout<<"00"<<endl;
// 				 	Node* m= rrt.all_nodes[i]->parent;

// 				 	cout<<(rrt.all_nodes[i]->parent==NULL)<<endl;
			 		
						
// 		 		//cout<<i<<endl;
// 		 		//cout<<(all_1[i]->P).x<<", ";
// 		 		//cout<<(all_1[i]->P).y<<endl;;
// 		 		}*/
// 				//cout<<rrt.shortest_path(rrt.start, rrt.final).size()<<endl;
// 				//cout<<rrt.all_nodes[7]->parent->P.y<<endl;
// 				//cout<<"12223473756686798090975675656355555555555"<<endl<<i<<endl;
// 				rrt.best_parent(new_n);
// 				rrt.rewire(new_n);
// 				Path= rrt.shortest_path(rrt.start, rrt.final);
				
// 			}
// 			else
// 			{
		
			
// 				//cout<<new_n->P.x<<endl;
// 				//cout<<new_n->P.y<<endl;

// 				rrt.best_parent(new_n);
				
// 				rrt.rewire(new_n);
// 				//cout<<endl;
// 				//cout<<rrt.all_nodes.size()<<endl;
// 				//cout<<(rrt.all_nodes[1]->P).x<<endl;
// 				//cout<<(rrt.all_nodes[1]->P).y<<endl;
// 				//cout<<4<<endl;
// 			}
// 		}
			
// 	}
// 	//cout<<666<<endl<<
// 	//cout<<Path.size()<<endl<<endl;
// 	float q= 0;

// 	 //for(int i=0;i<Path.size();i++)
// 	 //{
// 	 	//cout<<Path[i].x<< ", "<< Path[i].y<< endl;

// 	 //}

// 	vector<Node*> all_1= rrt.all_nodes;
// 	 //cout<<123456<<endl<<all_1.size()<<endl;

// 	 /*for(int i=0; i<rrt.all_nodes.size(); i++)
// 	 {
// 	 	if((rrt.all_nodes[i]->P.x - 0)<0.0001)
// 			cout<<"122234737566867980909756756563"<<endl;;
// 	 	//cout<<i<<endl;
// 	 	cout<<(rrt.all_nodes[i]->P).x<<", ";
// 	 	cout<<(rrt.all_nodes[i]->P).y<<endl;
// 	 	//cout<<rrt.obstacle_check(rrt.all_nodes[i], arr)<<endl;
// 	 	if(rrt.obstacle_check(rrt.all_nodes[i], arr)==0)
// 	 	{
// 			cout<<i<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
// 			break;
// 	 	}
// 	 	if(abs(rrt.all_nodes[i]->P.x- 19.5546)<0.1)
// 	 		cout<<"((((((((((((((((((((((((((((((("<<endl<<i<<endl;

// 	 }
// 	 cout<<random_nodes.size()<<endl;*/


// 	 //for(int i=0; i<random_nodes.size(); i++)
// 	 //{
// 	 //	cout<<random_nodes[i].x<<", "<<random_nodes[i].y<<endl;
// 	 //}
// 	 //cout<<33333<<endl;
// 	 //cout<<endl<<rrt.all_nodes[1]->P.x<<endl;
// 	 //cout<<rrt.all_nodes[2]->P.x<<endl<<rrt.all_nodes[2]->P.y<<endl;;
// 	 //cout<<Path.size()<<endl;
	 
// 	 cout<<endl<<rrt.final->cost<<endl;
// 	 cout<<rrt.linejoin_check(rrt.start, rrt.final)<<endl<<666<<endl;;

// 	 //cout<<rrt.all_nodes[7]->P.y;
	 
	 
	 
	 
// 	 int s=1;
// 	//m.x= 1/(s+distance(rrt.all_nodes[1]->P, rrt.all_nodes[0]))*(s*((rrt.all_nodes[1]->P).x) + (distance(rrt.all_nodes[1]->P, rrt.all_nodes[0]->P) - s)*((rrt.all_nodes[0]->P).x));
// 	//m.y= 1/(s+distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 	//Node* v= rrt.start->parent;
// 	//cout<<v->P.y<<endl;
// 	 return Path;

// }
// int main(int argc, char **argv)
// {
// 	// for(int i=0; i<=gridx; i++)
// 	// 	for(int j=0; j<=gridy;j++)
// 	// 		arr_1[i][j]= 0;

// 	// for(int i=0; i<s; i++)
// 	// {
// 	// 	for(int j=arr[i][0]; j<arr[i][1]; j++)
// 	// 	{
// 	// 		for(int k=arr[i][2]; k<arr[i][3]; k++)
// 	// 		{
// 	// 			arr_1[j][k]= 1;
// 	// 		}
// 	// 	}
// 	// }

// 	// RRT q;
// 	// cout<<66666<<endl;
// 	// Node* o= new Node;
// 	// o->P= {60, 90};
// 	// cout<<9999<<endl;
// 	// cout<<11111111<<endl<<q.obstacle_check(o)<<endl;



// 		vector<Point> Path= find_path();


// 		/*cout<<1111;
// 		Node* ab; 
// 		Node* cd;
// 		ab->P= Path[0];
// 		cd->P= Path[21];
// 		RRT a1;
// 		cout<<a1.linejoin_check(ab, cd);

// 		for(int i=0;i<Path.size();i++)
// 	 	{
// 	 	cout<<i<<endl<<Path[i].x<< ", "<< Path[i].y<< endl;

// 	 	}*/

// 		int count= 0;

// 	 ros::init(argc, argv, "rrt");

// 	 ros::NodeHandle v;
// 	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 	 ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1000);
// 	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1000);
// 	 ros::Rate loop_rate(10);

// 	nav_msgs::Path poses;
// 	poses.header.frame_id = "map";

// 	nav_msgs::OccupancyGrid MyGrid;

// 	MyGrid.header.stamp = ros::Time::now();
// 	MyGrid.header.frame_id = "map";
// 	MyGrid.info.resolution = 1.0;
// 	MyGrid.info.origin.position.x = 0.0;
// 	MyGrid.info.origin.position.y = 0.0;
// 	MyGrid.info.origin.position.z = 0.0;
// 	MyGrid.info.origin.orientation.x = 0.0;
// 	MyGrid.info.origin.orientation.y = 0.0;
// 	MyGrid.info.origin.orientation.z = 0.0;
// 	MyGrid.info.origin.orientation.w = 0.0;
// 	MyGrid.info.width = 100;
// 	MyGrid.info.height = 100;
// 	MyGrid.info.map_load_time = ros::Time::now();

// 	bool b= true;
// 	int xcvb = 0;
// 	for(int i=0;i<100;i++)
// 	{
// 		for(int j=0;j<100;j++)
// 		{
// 			b = true;
// 			for(int k=0; k<s; k++)
// 			{
// 				if(i> arr[k][0] && i<arr[k][1] && j> arr[k][2] && j< arr[k][3])
// 				{
// 					xcvb++;
// 					MyGrid.data.push_back(100);
// 					b= false;
// 					break;
// 				}
// 			}
// 			if(b)
// 			{
// 				xcvb++;
// 				MyGrid.data.push_back(0);
// 			}
// 		}
// 	}
// 	cout<<xcvb<<" asd"<<endl;
// 	 while (ros::ok())
// 	 {
// 	 	poses.poses.clear();
// 		cout<<count<<endl;

// 		for(int i=0; i<Path.size(); i++)
// 		{
// 			geometry_msgs::PoseStamped vertex;
// 			vertex.pose.position.x= Path[i].x;
// 			vertex.pose.position.y= Path[i].y;
// 			vertex.pose.position.z= 0;

		

		
// 			poses.poses.push_back(vertex);
// 		}

// 		chatter_pub.publish(poses);
// 		map_pub.publish(MyGrid);

//     ros::spinOnce();

//     loop_rate.sleep();

//     	count++;
		
// 	 }
  

// 	return 0;
// }


















// #include<iostream>
// #include<vector>
// #include<stdlib.h>
// #include<time.h>
// #include<math.h>
// #include "ros/ros.h"
//  #include "std_msgs/Header.h"
// #include "geometry_msgs/Pose.h"
// #include "nav_msgs/MapMetaData.h"
// #include "nav_msgs/OccupancyGrid.h"
// #include "nav_msgs/Path.h"
// // #include <typeinfo>
// using namespace std;


// float stepsize= 1;
// float radius= 7 ;
// float goal_radius= 1;

// float arr[2][4]= {{20, 50, 20, 50}, {50, 80, 50, 80}};
// int s= sizeof(arr)/sizeof(arr[0]);

// int c1 = 0;

// struct Point
// {
// 	double x;
// 	double y;
// };

// struct Node
// {

// 	float cost;
// 	Point P; 
// 	Node *parent;

// };

// const int goalx = 95;
// const int goaly = 95;
// const int begx = 1;
// const int begy = 1;

// const int gridx = 100;
// const int gridy = 100;

// Point gridSize = {gridx, gridy};

// Point goal= {goalx, goaly};
// Point beg= {begx, begy};

// //int arr_1[abs(goal.x-beg.x+1)][abs(goal.y-beg.y+1)];

// /*for(int i=0; i<abs(goal.x-beg.x+1); i++)
// 	for(int j=0; j<abs(goal.y-beg.y+1))
// 		arr_1[i][j]= 0;
// for(int i=0; i<s; i++)
// {
// 	for(int j=arr[i][0]; j<=arr[i][1]; j++)
// 		for(int k=arr[i][2]; k<=arr[i][3]; j++)
// 			arr_1[i][j]= 1;
// }*/

// int arr_1[gridx][gridy];

// Point x_centre= {(goal.x+beg.x)/2, (goal.y+beg.y)/2};


// float c_min= sqrt((goal.x-beg.x)*(goal.x-beg.x) + (goal.y-beg.y)*(goal.y-beg.y));
// float C[2][2]= {{(goal.x-beg.x)/c_min, (goal.x-beg.x)/c_min}, {(goal.y-beg.y)/c_min, (goal.y-beg.y)/c_min}} ;


// class RRT
// {
// public:
// 	Node* start = new Node;
// 	// start = &dd;
// 	vector<Node*> all_nodes;
// 	Node* final = new Node;
// 	Node sstart;
// 	RRT()
// 	{
		
		
// 		//cout<<"aa "<<(*start).P.x<<endl;
// 		//cout<<start->P.x<<endl;
		
// 		//cout<<sstart.P.x<<endl;
// 		(*start).P.x = beg.x;
		
// 		(*start).P.y = beg.y;
		
// 		start->parent= NULL;
		
// 		start->cost= 0;
		
// 		all_nodes.push_back(start);
		
// 		final->parent= NULL;
		
// 	}
// 	Node* generate_randnode()
// 	{
// 		Point p= {(rand() % int(gridSize.x+1)) + 1, ((rand() % int(gridSize.y+1)) + 1)};
// 		bool a= true;
// 		/*cout<<"sssssss"<<endl;
// 		for(int i= 0; i< all_nodes.size(); i++)
// 		{
// 			//cout<<"sssssss"<<endl;
// 			if(((p.x= (all_nodes[i]->P).x) && (p.y= (all_nodes[i]->P).y)))
// 				a= false;
				
// 		}*/
// 		if(a)
// 		{
// 			Node* rand_node= new Node;
// 			rand_node-> P= p;
// 			rand_node-> parent= NULL;
// 			return rand_node;
// 		}
// 		else
// 			generate_randnode();
// 	}
		


// 	/*float** multiply_matrices(float a[2][2], float b[2][2])
// 	{
// 		// float** c;
// 		float** c= new float*[2];
// 		c[0]= new float[2];
// 		c[1]= new float[2];
// 		c[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
// 		c[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];
// 		c[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
// 		c[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
// 		return c;
// 	}
// 	float* multiply_matr_vec(float a[2][2], float b[2])
// 	{
// 		float c_1[2];
// 		c_1[0]= a[0][0]*b[0] + a[0][1]*b[1];
// 		c_1[1]= a[1][0]*b[0] + a[1][1]*b[1];
// 		return c_1;
// 	}
// 	Node* sample(float c_best)
// 	{
// 		float r= (float) rand()/RAND_MAX;
// 		float theta= (float) rand()/RAND_MAX* 2*22/7;
// 		float s_1[2];
// 		s_1[0]= r*cos(theta);
// 		s_1[1]= r*sin(theta);
// 		float L[2][2]= {{0,0}, {0,0}};
// 		L[0][0]= c_best/2;
// 		L[1][1]= 0.5*sqrt(c_best*c_best - c_min*c_min);
// 		float** k=multiply_matrices(C, L);
		
// 		float* p= multiply_matr_vec(&&k, s_1);
// 		Point n;
// 		n.x= p[0]+x_centre.x;
// 		n.y= p[1]+x_centre.y;
// 		Node* rand_1;
// 		rand_1->P= n;
// 		if((obstacle_check(rand_1)) && n.x<= gridSize.x && n.y<= gridSize.y)
// 		{
// 			rand_1->parent= NULL;
// 			return rand_1;
// 		}
// 		else
// 			sample(c_best);
// 	}*/

// 	vector<Node*> near_nodes(Node* N)
// 	{
// 		//cout<<12345<<endl;
// 		vector<Node*> nearby_nodes;
// 		int e=1;
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			if(distance(all_nodes[i]->P, N->P)< radius)
// 			{
// 				// cout<<"boom "<<all_nodes[i]->P.x<<" "<<all_nodes[i]->P.y<<endl;
// 				nearby_nodes.push_back(all_nodes[i]);
// 			}
// 			if(all_nodes[i]==N)
// 			{
// 				//cout<<i;
// 				e=i;
// 			}
// 		}
// 		//cout<<endl<<3<<endl;
// 		//nearby_nodes.erase(nearby_nodes.begin()+ e);
// 		//cout<<nearby_nodes.size()<<endl<<"11236432875260746597284343798247897432894890952"<<endl;
// 		return nearby_nodes;
// 	}



// 	bool obstacle_check(Node* N)
// 	{
// 		//cout<<"yay \n";
// 		//cout<<c1<<endl;
		
// 		//c1++;

// 		Point p= N->P;
// 		for(int i=0; i<s; i++)
// 		{
// 			if((p.x>=(arr[i][0])&&p.x<=(arr[i][1])) && (p.y>=(arr[i][2])&&p.y<=(arr[i][3])))
// 				return false;
// 		}
// 		return true;
// 	}

// 	/*bool obstacle_check_1(Node* N)
// 	{
// 		// if(abs(rand()) % 2 == 0)
// 		// {
// 		// 	cout << "false" << N->cost<< endl;
// 		// 	return false;
// 		// }
// 		// else
// 		// {
// 		// 	cout << "true" << endl;
// 		// 	return true;
// 		// }
// 		cout<<"yay \n";
// 		cout<<c1<<endl;
		
// 		c1++;
// 		Point p= N->P;
// 		// int a, b;
// 		// a= p.x;
// 		// b= p.y;
// 		// cout<< "x " << int(p.x) << "  y " << int(p.y) <<endl;

// 		if(arr_1[int(p.x)][int(p.y)]==1)
// 			return false;
// 		return true;
// 	}*/




// 	bool linejoin_check(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		Node* N_1= new Node;
// 		Node* N_2= new Node;
// 		Node* N_3= new Node;
// 		Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
// 		Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
// 		Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
// 		N_1->P= n_1;
// 		N_2->P= n_2;
// 		N_3->P= n_3;
// 		if(!(obstacle_check(N_1)))
// 			return 0;
// 		// else if(!(obstacle_check(N_2)))
// 		// 	return 0;
// 		// else if(!(obstacle_check(N_3)))
// 		// 	return 0;
// 		else
// 			return 1;
// 	}


// 	Node* nearest_node(Node* N)
// 	{
// 		Node* nearest= new Node;
// 		float d= 1000000;
// 		float m;
// 		//vector<Node*> all_= near_nodes(N);

// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			m= distance(all_nodes[i]->P, N->P);
// 			if(m<d)
// 			{
// 				d= m;
// 				nearest= all_nodes[i];
// 			}	
// 		}
// 		return nearest;
// 	}


// 	Node* new_node(Node* nearest, Node* N)
// 	{
// 		Node* new_node= new Node;
// 		float s= stepsize;
// 		Point m;
// 		//cout<<distance(nearest->P, N->P)<<endl;
// 		if(distance(N->P, nearest->P)< s)
// 		{
// 			new_node->P= N->P;
// 			new_node->cost= nearest->cost+ distance(N->P, nearest->P);
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}
// 		else
// 		{
// 			m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
// 			m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 			new_node->P= m;
// 		}
// 		//cout<<nearest->P.x<<endl<<nearest->P.y<<endl;
// 		//cout<<"00000000000000"<<endl<<m.x<<endl<<m.y<<endl;
// 		int a= 1;
// 		//cout<<!obstacle_check(new_node, arr)<<endl;
// 		while(a && s> 0.01*stepsize)
// 		{
// 			if(!obstacle_check(new_node))
// 			{
				

// 				(new_node->P).x= 0.9*(new_node->P).x+ 0.1*(nearest->P).x;
// 				(new_node->P).y= 0.9*(new_node->P).y+ 0.1*(nearest->P).y;
// 				s*= 0.9;   
// 				//cout<<new_node->P.x<<endl<<new_node->P.y<<endl<<endl;
// 			}
// 			else
// 			{
// 				a= 0;
// 				new_node->cost= nearest->cost+ s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}

// 		}	
// 		/*if(a==0)
// 		{
// 			new_node->cost= nearest->cost+ s;
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}*/

// 			//cout<<a<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
// 			return NULL;
		
// 	}


// 	float distance(Point a, Point b)
// 	{
// 		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
// 	}




// 	Node* best_parent(Node* N)
// 	{
// 		vector<Node*> q= near_nodes(N);
// 		//cout<<"6666666666"<<q.size()<<endl;
// 		Node* best= new Node;
// 		best->cost = 10000000;
// 		float best_cost = best->cost;
// 		float now_cost = best->cost;
// 		// cout<<"innnnnnnnnnnnnnn"<<endl;
// 		for(int i= 0; i<q.size(); i++)
// 		{
// 			//cout<<"cost"<<" "<<q[i]->cost<<endl;
// 			if(!(q[i]== N))
// 				//cout<<"shoot "<<q[i]->cost<<endl;
// 				//+ distance(q[i]->P, N->P)
// 				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
// 				if(now_cost < best_cost)
// 				{
// 					//cout<<"in here"<<q[i]->P.x<<" "<<q[i]->P.y<<" "<<linejoin_check(q[i], N)<<endl;
					
// 					if((linejoin_check(q[i], N)))
// 					{
// 						best= q[i];
// 						// cout<<"asdfghjkl"<<endl;
// 						best_cost = now_cost;
// 						// best->cost = best_cost;
// 					}
// 				}
// 		}
// 		// cout<<"fu"<<endl;
// 		if(!(q.size()==1))
// 		{
// 			// cout<<"in here"<<best->P.x<<" "<<best->P.y<<endl;
// 			// cout<<"8888888888888"<<endl;
// 			N->cost= best_cost;
// 			N->parent= best;
// 			return best;
// 		}
// 		else
// 		{
// 			// cout<<"1111111111111"<<endl;
// 			return N->parent;
// 		}	
// 	}

// 	void rewire(Node* N)
// 	{
// 		vector<Node*> w= near_nodes(N);
// 		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
// 			w.push_back(final);
// 		//cout<<w.size();
// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if(best_parent(N)== w[i])
// 			{
// 				w.erase(w.begin()+ i);
// 				break;
// 			}
			
// 		}
// 		//cout<<endl<<w.size();
// 		//cout<<"£££££££££££££££££££££££££££££££££££"<<endl;

// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost)
// 			{
// 				//cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
// 				if((linejoin_check(N, w[i])))
// 				{
// 					w[i]->parent= N;
// 					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
// 				}
// 			}
// 		}

// 	}

// 	bool goal_check(Node* N, Point goal)
// 	{
// 		if(distance(N->P, goal) < goal_radius)
// 		{
// 			final->parent= N;
// 			final->P= goal;
// 			final->cost= N->cost+ distance(N->P, goal);
// 			return true;
// 		}
// 		return false;
// 	}

// 	vector<Point> shortest_path(Node* start, Node* final)
// 	{
// 		vector<Point> path;
		
// 		Node* a= final;
// 		int i=1;
// 		//cout<<98765<<endl;
// 		//cout<<start->P.x<<endl;
// 			while(!(a->parent== NULL))
// 			{
// 				//cout<<i<<endl;

// 				path.push_back(a->P);
// 				//cout<<path.size()<<endl;
// 				if((a->parent==start))
// 					path.push_back(start->P);
// 				a= a->parent;
// 				/*if(i==2)
// 				{
// 					cout<<7<<endl<<a->P.x<<endl;
// 					cout<<1111<<endl<<(a->parent==NULL)<<endl;
// 				}
				
// 				if(i==3)
// 				{
// 					cout<<2222222222<<endl;
// 				}*/


				
// 				i++;
				
// 			}
			
// 			//path.push_back(start->P);
// 		return path;
// 	}


// };



// vector<Point> find_path()
// {
// 	//int n= 1;
// 	//cin >> n;
// 	//float arr[4];
// 	//arr[0]= 10;
// 	//arr[1]= 90;
// 	//arr[2]= 10;
// 	//arr[3]= 90;
// 	//cout<<"aaaaaaa"<<endl;

// 	//for(int i=0; i<(sizeof(arr))/32; i++)
// 	//{
// 		//for(int j=0; j<4; j++)
// 		//	cin>> arr[i][j];
// 	//}


// 	RRT rrt;	
// 	Point goal;
// 	int X, Y;
// 	X= 95;
// 	Y= 95;
// 	goal.x= X;
// 	goal.y= Y;
// 	bool c= 0;

// 	int iter_max= 5000;
// 	vector<Point> Path;
// 	vector<Point> random_nodes;
// 	Node* rand_n= new Node;
// 	Node* nearest_1= new Node;
// 	Node* new_n= new Node;

// 	//cout<<888<<endl<<rrt.start->parent<<endl;
// 	int check= 1;


// 	for(int i= 1; i<iter_max; i++)
// 	{	
// 		// c1 = 0;
// 		//cout<<endl<<i<<endl;
// 		//if(c==1)
// 		//	rand_n= rrt.sample(rrt.final->cost);
// 		//else
// 			rand_n= rrt.generate_randnode();
// 		random_nodes.push_back(rand_n->P);
		
		
		
		
// 		nearest_1= rrt.nearest_node(rand_n);
// 		//if(i==4)
// 		//	cout<<"ssssssss"<<endl<<nearest_1->P.x<<endl<<rand_n->P.x<<endl;
// 		//cout<<7777<<endl;
// 		//cout<<rrt.all_nodes.size()<<endl;
		
		
// 		//cout<<new_n->P.y<<endl;
// 		//rrt.best_parent(new_n);
		
// 		//new_n->parent= b;
// 		//rrt.rewire(new_n);



		
		
// 		new_n= rrt.new_node(nearest_1, rand_n);
// 		//cout<<new_n<<endl;
// 		if(!(new_n==NULL))
// 		{
			

			

// 			if(check==1)
// 			{
// 				if(rrt.goal_check(new_n, goal))
// 					check=0;
// 			}
			

// 			c= !(rrt.final->parent== NULL);
// 			//cout<<c<<endl;

// 			if(c==1)
// 			{
// 				//cout<<i<<endl<<"555555555555555555555555555"<<endl;
// 				/*for(int i=0; i<rrt.all_nodes.size(); i++)
// 				 {
// 				 	cout<<rrt.all_nodes[i]->P.x <<endl;
// 				 	cout<<"00"<<endl;
// 				 	Node* m= rrt.all_nodes[i]->parent;
// 				 	cout<<(rrt.all_nodes[i]->parent==NULL)<<endl;
			 		
						
// 		 		//cout<<i<<endl;
// 		 		//cout<<(all_1[i]->P).x<<", ";
// 		 		//cout<<(all_1[i]->P).y<<endl;;
// 		 		}*/
// 				//cout<<rrt.shortest_path(rrt.start, rrt.final).size()<<endl;
// 				//cout<<rrt.all_nodes[7]->parent->P.y<<endl;
// 				//cout<<"12223473756686798090975675656355555555555"<<endl<<i<<endl;
// 				rrt.best_parent(new_n);
// 				rrt.rewire(new_n);
// 				Path= rrt.shortest_path(rrt.start, rrt.final);
				
// 			}
// 			else
// 			{
		
			
// 				//cout<<new_n->P.x<<endl;
// 				//cout<<new_n->P.y<<endl;

// 				rrt.best_parent(new_n);
				
// 				rrt.rewire(new_n);
// 				//cout<<endl;
// 				//cout<<rrt.all_nodes.size()<<endl;
// 				//cout<<(rrt.all_nodes[1]->P).x<<endl;
// 				//cout<<(rrt.all_nodes[1]->P).y<<endl;
// 				//cout<<4<<endl;
// 			}
// 		}
			
// 	}
// 	//cout<<666<<endl<<
// 	//cout<<Path.size()<<endl<<endl;
// 	float q= 0;

// 	 //for(int i=0;i<Path.size();i++)
// 	 //{
// 	 	//cout<<Path[i].x<< ", "<< Path[i].y<< endl;

// 	 //}

// 	vector<Node*> all_1= rrt.all_nodes;
// 	 //cout<<123456<<endl<<all_1.size()<<endl;

// 	 /*for(int i=0; i<rrt.all_nodes.size(); i++)
// 	 {
// 	 	if((rrt.all_nodes[i]->P.x - 0)<0.0001)
// 			cout<<"122234737566867980909756756563"<<endl;;
// 	 	//cout<<i<<endl;
// 	 	cout<<(rrt.all_nodes[i]->P).x<<", ";
// 	 	cout<<(rrt.all_nodes[i]->P).y<<endl;
// 	 	//cout<<rrt.obstacle_check(rrt.all_nodes[i], arr)<<endl;
// 	 	if(rrt.obstacle_check(rrt.all_nodes[i], arr)==0)
// 	 	{
// 			cout<<i<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
// 			break;
// 	 	}
// 	 	if(abs(rrt.all_nodes[i]->P.x- 19.5546)<0.1)
// 	 		cout<<"((((((((((((((((((((((((((((((("<<endl<<i<<endl;
// 	 }
// 	 cout<<random_nodes.size()<<endl;*/


// 	 //for(int i=0; i<random_nodes.size(); i++)
// 	 //{
// 	 //	cout<<random_nodes[i].x<<", "<<random_nodes[i].y<<endl;
// 	 //}
// 	 //cout<<33333<<endl;
// 	 //cout<<endl<<rrt.all_nodes[1]->P.x<<endl;
// 	 //cout<<rrt.all_nodes[2]->P.x<<endl<<rrt.all_nodes[2]->P.y<<endl;;
// 	 //cout<<Path.size()<<endl;
	 
// 	 cout<<endl<<rrt.final->cost<<endl;
// 	 cout<<rrt.linejoin_check(rrt.start, rrt.final)<<endl<<666<<endl;;

// 	 //cout<<rrt.all_nodes[7]->P.y;
	 
	 
	 
	 
// 	 int s=1;
// 	//m.x= 1/(s+distance(rrt.all_nodes[1]->P, rrt.all_nodes[0]))*(s*((rrt.all_nodes[1]->P).x) + (distance(rrt.all_nodes[1]->P, rrt.all_nodes[0]->P) - s)*((rrt.all_nodes[0]->P).x));
// 	//m.y= 1/(s+distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 	//Node* v= rrt.start->parent;
// 	//cout<<v->P.y<<endl;
// 	 return Path;

// }
// int main(int argc, char **argv)

// {
// 	for(int i=0; i<=gridx; i++)
// 		for(int j=0; j<=gridy;j++)
// 			arr_1[i][j]= 0;

// 	for(int i=0; i<s; i++)
// 	{
// 		for(int j=arr[i][0]; j<arr[i][1]; j++)
// 		{
// 			for(int k=arr[i][2]; k<arr[i][3]; k++)
// 			{
// 				arr_1[j][k]= 1;
// 			}
// 		}
// 	}

// 		// for(int i=0; i<=gridx; i++)
// 		// 	for(int j=0; j<=gridy;j++)
// 		// 		cout<<arr_1[i][j];

// 		cout<<2222;
// 		vector<Point> Path= find_path();


// 		/*cout<<1111;
// 		Node* ab; 
// 		Node* cd;
// 		ab->P= Path[0];
// 		cd->P= Path[21];
// 		RRT a1;
// 		cout<<a1.linejoin_check(ab, cd);
// 		for(int i=0;i<Path.size();i++)
// 	 	{
// 	 	cout<<i<<endl<<Path[i].x<< ", "<< Path[i].y<< endl;
// 	 	}*/

// 		int count= 0;

// 	 ros::init(argc, argv, "rrt");

// 	 ros::NodeHandle v;
// 	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 	 ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1000);
// 	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1000);
// 	 ros::Rate loop_rate(10);

// 	nav_msgs::Path poses;
// 	poses.header.frame_id = "map";

// 	nav_msgs::OccupancyGrid MyGrid;

// 	MyGrid.header.stamp = ros::Time::now();
// 	MyGrid.header.frame_id = "map";
// 	MyGrid.info.resolution = 1.0;
// 	MyGrid.info.origin.position.x = 0.0;
// 	MyGrid.info.origin.position.y = 0.0;
// 	MyGrid.info.origin.position.z = 0.0;
// 	MyGrid.info.origin.orientation.x = 0.0;
// 	MyGrid.info.origin.orientation.y = 0.0;
// 	MyGrid.info.origin.orientation.z = 0.0;
// 	MyGrid.info.origin.orientation.w = 0.0;
// 	MyGrid.info.width = 100;
// 	MyGrid.info.height = 100;
// 	MyGrid.info.map_load_time = ros::Time::now();

// 	bool b= true;
// 	int xcvb = 0;
// 	for(int i=0;i<100;i++)
// 	{
// 		for(int j=0;j<100;j++)
// 		{
// 			b = true;
// 			for(int k=0; k<s; k++)
// 			{
// 				if(i> arr[k][0] && i<arr[k][1] && j> arr[k][2] && j< arr[k][3])
// 				{
// 					xcvb++;
// 					MyGrid.data.push_back(100);
// 					b= false;
// 					break;
// 				}
// 			}
// 			if(b)
// 			{
// 				xcvb++;
// 				MyGrid.data.push_back(0);
// 			}
// 		}
// 	}
// 	cout<<xcvb<<" asd"<<endl;
// 	 while (ros::ok())
// 	 {
// 	 	poses.poses.clear();
// 		cout<<count<<endl;

// 		for(int i=0; i<Path.size(); i++)
// 		{
// 			geometry_msgs::PoseStamped vertex;
// 			vertex.pose.position.x= Path[i].x;
// 			vertex.pose.position.y= Path[i].y;
// 			vertex.pose.position.z= 0;

		

		
// 			poses.poses.push_back(vertex);
// 		}

// 		chatter_pub.publish(poses);
// 		map_pub.publish(MyGrid);

//     ros::spinOnce();

//     loop_rate.sleep();

//     	count++;
		
// 	 }
  

// 	return 0;
// }






// #include<iostream>
// #include<vector>
// #include<stdlib.h>
// #include<time.h>
// #include<math.h>
// #include "ros/ros.h"
//  #include "std_msgs/Header.h"
// #include "geometry_msgs/Pose.h"
// #include "nav_msgs/MapMetaData.h"
// #include "nav_msgs/OccupancyGrid.h"
// #include "nav_msgs/Path.h"
// // #include <typeinfo>
// using namespace std;


// float stepsize= 1;
// float radius= 7 ;
// float goal_radius= 1;

// float arr[2][4]= {{20, 50, 20, 50}, {50, 80, 50, 80}};
// int s= sizeof(arr)/sizeof(arr[0]);


// struct Point
// {
// 	double x;
// 	double y;
// };

// struct Node
// {

// 	float cost;
// 	Point P; 
// 	Node *parent;

// };

// const int goalx = 95;
// const int goaly = 95;
// const int begx = 1;
// const int begy = 1;

// const int gridx = 100;
// const int gridy = 100;

// Point gridSize = {gridx, gridy};

// Point goal= {goalx, goaly};
// Point beg= {begx, begy};

// int arr_1[gridx][gridy];


// /*for(int i=0; i<abs(goal.x-beg.x+1); i++)
// 	for(int j=0; j<abs(goal.y-beg.y+1))
// 		arr_1[i][j]= 0;
// for(int i=0; i<s; i++)
// {
// 	for(int j=arr[i][0]; j<=arr[i][1]; j++)
// 		for(int k=arr[i][2]; k<=arr[i][3]; j++)
// 			arr_1[i][j]= 1;
// }*/

// Point x_centre= {(goal.x+beg.x)/2, (goal.y+beg.y)/2};


// float c_min= sqrt((goal.x-beg.x)*(goal.x-beg.x) + (goal.y-beg.y)*(goal.y-beg.y));
// float C[2][2]= {{(goal.x-beg.x)/c_min, (goal.x-beg.x)/c_min}, {(goal.y-beg.y)/c_min, (goal.y-beg.y)/c_min}} ;


// class RRT
// {
// public:
// 	Node* start = new Node;
// 	// start = &dd;
// 	vector<Node*> all_nodes;
// 	Node* final = new Node;
// 	Node sstart;
// 	RRT()
// 	{
		
		
// 		//cout<<"aa "<<(*start).P.x<<endl;
// 		//cout<<start->P.x<<endl;
		
// 		//cout<<sstart.P.x<<endl;
// 		(*start).P.x = beg.x;
		
// 		(*start).P.y = beg.y;
		
// 		start->parent= NULL;
		
// 		start->cost= 0;
		
// 		all_nodes.push_back(start);
		
// 		final->parent= NULL;
		
// 	}
// 	Node* generate_randnode()
// 	{
// 		Point p= {(rand() % int(gridSize.x+1)) + 1, ((rand() % int(gridSize.y+1)) + 1)};
// 		bool a= true;
// 		/*cout<<"sssssss"<<endl;
// 		for(int i= 0; i< all_nodes.size(); i++)
// 		{
// 			//cout<<"sssssss"<<endl;
// 			if(((p.x= (all_nodes[i]->P).x) && (p.y= (all_nodes[i]->P).y)))
// 				a= false;
				
// 		}*/
// 		if(a)
// 		{
// 			Node* rand_node= new Node;
// 			rand_node-> P= p;
// 			rand_node-> parent= NULL;
// 			return rand_node;
// 		}
// 		else
// 			generate_randnode();
// 	}
		


// 	/*float** multiply_matrices(float a[2][2], float b[2][2])
// 	{
// 		// float** c;
// 		float** c= new float*[2];
// 		c[0]= new float[2];
// 		c[1]= new float[2];
// 		c[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
// 		c[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];
// 		c[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
// 		c[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
// 		return c;
// 	}
// 	float* multiply_matr_vec(float a[2][2], float b[2])
// 	{
// 		float c_1[2];
// 		c_1[0]= a[0][0]*b[0] + a[0][1]*b[1];
// 		c_1[1]= a[1][0]*b[0] + a[1][1]*b[1];
// 		return c_1;
// 	}
// 	Node* sample(float c_best)
// 	{
// 		float r= (float) rand()/RAND_MAX;
// 		float theta= (float) rand()/RAND_MAX* 2*22/7;
// 		float s_1[2];
// 		s_1[0]= r*cos(theta);
// 		s_1[1]= r*sin(theta);
// 		float L[2][2]= {{0,0}, {0,0}};
// 		L[0][0]= c_best/2;
// 		L[1][1]= 0.5*sqrt(c_best*c_best - c_min*c_min);
// 		float** k=multiply_matrices(C, L);
		
// 		float* p= multiply_matr_vec(&&k, s_1);
// 		Point n;
// 		n.x= p[0]+x_centre.x;
// 		n.y= p[1]+x_centre.y;
// 		Node* rand_1;
// 		rand_1->P= n;
// 		if((obstacle_check(rand_1)) && n.x<= gridSize.x && n.y<= gridSize.y)
// 		{
// 			rand_1->parent= NULL;
// 			return rand_1;
// 		}
// 		else
// 			sample(c_best);
// 	}*/

// 	vector<Node*> near_nodes(Node* N)
// 	{
// 		//cout<<12345<<endl;
// 		vector<Node*> nearby_nodes;
// 		int e=1;
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			if(distance(all_nodes[i]->P, N->P)< radius)
// 			{
// 				// cout<<"boom "<<all_nodes[i]->P.x<<" "<<all_nodes[i]->P.y<<endl;
// 				nearby_nodes.push_back(all_nodes[i]);
// 			}
// 			if(all_nodes[i]==N)
// 			{
// 				//cout<<i;
// 				e=i;
// 			}
// 		}
// 		//cout<<endl<<3<<endl;
// 		//nearby_nodes.erase(nearby_nodes.begin()+ e);
// 		//cout<<nearby_nodes.size()<<endl<<"11236432875260746597284343798247897432894890952"<<endl;
// 		return nearby_nodes;
// 	}



// 	bool obstacle_check(Node* N)
// 	{
// 		Point p= N->P;
// 		for(int i=0; i<s; i++)
// 		{
// 			if((p.x>=(arr[i][0])&&p.x<=(arr[i][1])) && (p.y>=(arr[i][2])&&p.y<=(arr[i][3])))
// 				return false;
// 		}
// 		return true;
// 	}


// 	bool obstacle_check_1(Node* N)
// 	{
// 		Point p= N->P;
// 		int a, b;
// 		a= p.x;
// 		b= p.y;
// 		if(arr_1[a][b]==1)
// 			return false;
// 		return true;
// 	}


// 	bool linejoin_check(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		Node* N_1= new Node;
// 		Node* N_2= new Node;
// 		Node* N_3= new Node;
// 		Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
// 		Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
// 		Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
// 		N_1->P= n_1;
// 		N_2->P= n_2;
// 		N_3->P= n_3;
// 		if(!(obstacle_check(N_1)))
// 			return 0;
// 		// else if(!(obstacle_check(N_2)))
// 		// 	return 0;
// 		// else if(!(obstacle_check(N_3)))
// 		// 	return 0;
// 		else
// 			return 1;
// 	}


// 	Node* nearest_node(Node* N)
// 	{
// 		Node* nearest= new Node;
// 		float d= 1000000;
// 		float m;
// 		//vector<Node*> all_= near_nodes(N);

// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			m= distance(all_nodes[i]->P, N->P);
// 			if(m<d)
// 			{
// 				d= m;
// 				nearest= all_nodes[i];
// 			}	
// 		}
// 		return nearest;
// 	}


// 	Node* new_node(Node* nearest, Node* N)
// 	{
// 		Node* new_node= new Node;
// 		float s= stepsize;
// 		Point m;
// 		//cout<<distance(nearest->P, N->P)<<endl;
// 		if(distance(N->P, nearest->P)< s)
// 		{
// 			new_node->P= N->P;
// 			new_node->cost= nearest->cost+ distance(N->P, nearest->P);
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}
// 		else
// 		{
// 			m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
// 			m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 			new_node->P= m;
// 		}
// 		//cout<<nearest->P.x<<endl<<nearest->P.y<<endl;
// 		//cout<<"00000000000000"<<endl<<m.x<<endl<<m.y<<endl;
// 		int a= 1;
// 		//cout<<!obstacle_check(new_node, arr)<<endl;
// 		while(a && s> 0.01*stepsize)
// 		{
// 			if(!obstacle_check(new_node))
// 			{	
// 				cout<<"zxcvbn\n";

// 				(new_node->P).x= 0.9*(new_node->P).x+ 0.1*(nearest->P).x;
// 				(new_node->P).y= 0.9*(new_node->P).y+ 0.1*(nearest->P).y;
// 				s*= 0.9;   
// 				//cout<<new_node->P.x<<endl<<new_node->P.y<<endl<<endl;
// 			}
// 			else
// 			{
// 				cout<<"qwertyuio\n";
// 				a= 0;
// 				new_node->cost= nearest->cost+ s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}

// 		}	
// 		cout<<all_nodes.size()<<" 123456789\n";
// 		/*if(a==0)
// 		{
// 			new_node->cost= nearest->cost+ s;
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}*/

// 			//cout<<a<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
// 			return NULL;
		
// 	}


// 	float distance(Point a, Point b)
// 	{
// 		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
// 	}




// 	Node* best_parent(Node* N)
// 	{
// 		vector<Node*> q= near_nodes(N);
// 		//cout<<"6666666666"<<q.size()<<endl;
// 		Node* best= new Node;
// 		best->cost = 10000000;
// 		float best_cost = best->cost;
// 		float now_cost = best->cost;
// 		// cout<<"innnnnnnnnnnnnnn"<<endl;
// 		for(int i= 0; i<q.size(); i++)
// 		{
// 			//cout<<"cost"<<" "<<q[i]->cost<<endl;
// 			if(!(q[i]== N))
// 				//cout<<"shoot "<<q[i]->cost<<endl;
// 				//+ distance(q[i]->P, N->P)
// 				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
// 				if(now_cost < best_cost)
// 				{
// 					//cout<<"in here"<<q[i]->P.x<<" "<<q[i]->P.y<<" "<<linejoin_check(q[i], N)<<endl;
					
// 					if((linejoin_check(q[i], N)))
// 					{
// 						best= q[i];
// 						// cout<<"asdfghjkl"<<endl;
// 						best_cost = now_cost;
// 						// best->cost = best_cost;
// 					}
// 				}
// 		}
// 		// cout<<"fu"<<endl;
// 		if(!(q.size()==1))
// 		{
// 			// cout<<"in here"<<best->P.x<<" "<<best->P.y<<endl;
// 			// cout<<"8888888888888"<<endl;
// 			N->cost= best_cost;
// 			N->parent= best;
// 			return best;
// 		}
// 		else
// 		{
// 			// cout<<"1111111111111"<<endl;
// 			return N->parent;
// 		}	
// 	}

// 	void rewire(Node* N)
// 	{
// 		vector<Node*> w= near_nodes(N);
// 		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
// 			w.push_back(final);
// 		//cout<<w.size();
// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if(best_parent(N)== w[i])
// 			{
// 				w.erase(w.begin()+ i);
// 				break;
// 			}
			
// 		}
// 		//cout<<endl<<w.size();
// 		//cout<<"£££££££££££££££££££££££££££££££££££"<<endl;

// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost)
// 			{
// 				//cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
// 				if((linejoin_check(N, w[i])))
// 				{
// 					w[i]->parent= N;
// 					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
// 				}
// 			}
// 		}

// 	}

// 	bool goal_check(Node* N, Point goal)
// 	{
// 		if(distance(N->P, goal) < goal_radius)
// 		{
// 			final->parent= N;
// 			final->P= goal;
// 			final->cost= N->cost+ distance(N->P, goal);
// 			return true;
// 		}
// 		return false;
// 	}

// 	vector<Point> shortest_path(Node* start, Node* final)
// 	{
// 		vector<Point> path;
		
// 		Node* a= final;
// 		int i=1;
// 		//cout<<98765<<endl;
// 		//cout<<start->P.x<<endl;
// 			while(!(a->parent== NULL))
// 			{
// 				//cout<<i<<endl;

// 				path.push_back(a->P);
// 				//cout<<path.size()<<endl;
// 				if((a->parent==start))
// 					path.push_back(start->P);
// 				a= a->parent;
// 				/*if(i==2)
// 				{
// 					cout<<7<<endl<<a->P.x<<endl;
// 					cout<<1111<<endl<<(a->parent==NULL)<<endl;
// 				}
				
// 				if(i==3)
// 				{
// 					cout<<2222222222<<endl;
// 				}*/


				
// 				i++;
				
// 			}
			
// 			//path.push_back(start->P);
// 		return path;
// 	}


// };



// vector<Point> find_path()
// {
// 	//int n= 1;
// 	//cin >> n;
// 	//float arr[4];
// 	//arr[0]= 10;
// 	//arr[1]= 90;
// 	//arr[2]= 10;
// 	//arr[3]= 90;
// 	//cout<<"aaaaaaa"<<endl;

// 	//for(int i=0; i<(sizeof(arr))/32; i++)
// 	//{
// 		//for(int j=0; j<4; j++)
// 		//	cin>> arr[i][j];
// 	//}


// 	RRT rrt;	
// 	Point goal;
// 	int X, Y;
// 	X= 95;
// 	Y= 95;
// 	goal.x= X;
// 	goal.y= Y;
// 	bool c= 0;

// 	int iter_max= 5000;
// 	vector<Point> Path;
// 	vector<Point> random_nodes;
// 	Node* rand_n= new Node;
// 	Node* nearest_1= new Node;
// 	Node* new_n= new Node;

// 	//cout<<888<<endl<<rrt.start->parent<<endl;
// 	int check= 1;


// 	for(int i= 1; i<iter_max; i++)
// 	{
// 		//cout<<endl<<i<<endl;
// 		//if(c==1)
// 		//	rand_n= rrt.sample(rrt.final->cost);
// 		//else
// 			rand_n= rrt.generate_randnode();
// 		random_nodes.push_back(rand_n->P);
		
		
		
		
// 		nearest_1= rrt.nearest_node(rand_n);
// 		//if(i==4)
// 		//	cout<<"ssssssss"<<endl<<nearest_1->P.x<<endl<<rand_n->P.x<<endl;
// 		//cout<<7777<<endl;
// 		//cout<<rrt.all_nodes.size()<<endl;
		
		
// 		//cout<<new_n->P.y<<endl;
// 		//rrt.best_parent(new_n);
		
// 		//new_n->parent= b;
// 		//rrt.rewire(new_n);



		
		
// 		new_n= rrt.new_node(nearest_1, rand_n);
// 		//cout<<new_n<<endl;
// 		if(!(new_n==NULL))
// 		{
			

			

// 			if(check==1)
// 			{
// 				if(rrt.goal_check(new_n, goal))
// 					check=0;
// 			}
			

// 			c= !(rrt.final->parent== NULL);
// 			//cout<<c<<endl;

// 			if(c==1)
// 			{
// 				//cout<<i<<endl<<"555555555555555555555555555"<<endl;
// 				/*for(int i=0; i<rrt.all_nodes.size(); i++)
// 				 {
// 				 	cout<<rrt.all_nodes[i]->P.x <<endl;
// 				 	cout<<"00"<<endl;
// 				 	Node* m= rrt.all_nodes[i]->parent;
// 				 	cout<<(rrt.all_nodes[i]->parent==NULL)<<endl;
			 		
						
// 		 		//cout<<i<<endl;
// 		 		//cout<<(all_1[i]->P).x<<", ";
// 		 		//cout<<(all_1[i]->P).y<<endl;;
// 		 		}*/
// 				//cout<<rrt.shortest_path(rrt.start, rrt.final).size()<<endl;
// 				//cout<<rrt.all_nodes[7]->parent->P.y<<endl;
// 				//cout<<"12223473756686798090975675656355555555555"<<endl<<i<<endl;
// 				rrt.best_parent(new_n);
// 				rrt.rewire(new_n);
// 				Path= rrt.shortest_path(rrt.start, rrt.final);
				
// 			}
// 			else
// 			{
		
			
// 				//cout<<new_n->P.x<<endl;
// 				//cout<<new_n->P.y<<endl;

// 				rrt.best_parent(new_n);
				
// 				rrt.rewire(new_n);
// 				//cout<<endl;
// 				//cout<<rrt.all_nodes.size()<<endl;
// 				//cout<<(rrt.all_nodes[1]->P).x<<endl;
// 				//cout<<(rrt.all_nodes[1]->P).y<<endl;
// 				//cout<<4<<endl;
// 			}
// 		}
			
// 	}
// 	//cout<<666<<endl<<
// 	//cout<<Path.size()<<endl<<endl;
// 	float q= 0;

// 	 //for(int i=0;i<Path.size();i++)
// 	 //{
// 	 	//cout<<Path[i].x<< ", "<< Path[i].y<< endl;

// 	 //}

// 	vector<Node*> all_1= rrt.all_nodes;
// 	 //cout<<123456<<endl<<all_1.size()<<endl;

// 	 /*for(int i=0; i<rrt.all_nodes.size(); i++)
// 	 {
// 	 	if((rrt.all_nodes[i]->P.x - 0)<0.0001)
// 			cout<<"122234737566867980909756756563"<<endl;;
// 	 	//cout<<i<<endl;
// 	 	cout<<(rrt.all_nodes[i]->P).x<<", ";
// 	 	cout<<(rrt.all_nodes[i]->P).y<<endl;
// 	 	//cout<<rrt.obstacle_check(rrt.all_nodes[i], arr)<<endl;
// 	 	if(rrt.obstacle_check(rrt.all_nodes[i], arr)==0)
// 	 	{
// 			cout<<i<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
// 			break;
// 	 	}
// 	 	if(abs(rrt.all_nodes[i]->P.x- 19.5546)<0.1)
// 	 		cout<<"((((((((((((((((((((((((((((((("<<endl<<i<<endl;
// 	 }
// 	 cout<<random_nodes.size()<<endl;*/


// 	 //for(int i=0; i<random_nodes.size(); i++)
// 	 //{
// 	 //	cout<<random_nodes[i].x<<", "<<random_nodes[i].y<<endl;
// 	 //}
// 	 //cout<<33333<<endl;
// 	 //cout<<endl<<rrt.all_nodes[1]->P.x<<endl;
// 	 //cout<<rrt.all_nodes[2]->P.x<<endl<<rrt.all_nodes[2]->P.y<<endl;;
// 	 //cout<<Path.size()<<endl;
	 
// 	 cout<<endl<<rrt.final->cost<<endl;
// 	 cout<<rrt.linejoin_check(rrt.start, rrt.final)<<endl<<666<<endl;;

// 	 //cout<<rrt.all_nodes[7]->P.y;
	 
	 
	 
	 
// 	 int s=1;
// 	//m.x= 1/(s+distance(rrt.all_nodes[1]->P, rrt.all_nodes[0]))*(s*((rrt.all_nodes[1]->P).x) + (distance(rrt.all_nodes[1]->P, rrt.all_nodes[0]->P) - s)*((rrt.all_nodes[0]->P).x));
// 	//m.y= 1/(s+distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 	//Node* v= rrt.start->parent;
// 	//cout<<v->P.y<<endl;
// 	 return Path;

// }
// 	int main(int argc, char **argv)

// 	{

// 		for(int i=0; i<=gridx; i++)
// 			for(int j=0; j<=gridy;j++)
// 				arr_1[i][j]= 0;

// 		for(int i=0; i<s; i++)
// 		{
// 			for(int j=arr[i][0]; j<arr[i][1]; j++)
// 			{
// 				for(int k=arr[i][2]; k<arr[i][3]; k++)
// 				{
// 						arr_1[j][k]= 1;
// 				}
// 			}
// 		}
// 		cout<<2222;
// 		vector<Point> Path= find_path();


// 		/*cout<<1111;
// 		Node* ab; 
// 		Node* cd;
// 		ab->P= Path[0];
// 		cd->P= Path[21];
// 		RRT a1;
// 		cout<<a1.linejoin_check(ab, cd);
// 		for(int i=0;i<Path.size();i++)
// 	 	{
// 	 	cout<<i<<endl<<Path[i].x<< ", "<< Path[i].y<< endl;
// 	 	}*/

// 		int count= 0;

// 	 ros::init(argc, argv, "rrt");

// 	 ros::NodeHandle v;
// 	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 	 ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1000);
// 	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1000);
// 	 ros::Rate loop_rate(10);

// 	nav_msgs::Path poses;
// 	poses.header.frame_id = "map";

// 	nav_msgs::OccupancyGrid MyGrid;

// 	MyGrid.header.stamp = ros::Time::now();
// 	MyGrid.header.frame_id = "map";
// 	MyGrid.info.resolution = 1.0;
// 	MyGrid.info.origin.position.x = 0.0;
// 	MyGrid.info.origin.position.y = 0.0;
// 	MyGrid.info.origin.position.z = 0.0;
// 	MyGrid.info.origin.orientation.x = 0.0;
// 	MyGrid.info.origin.orientation.y = 0.0;
// 	MyGrid.info.origin.orientation.z = 0.0;
// 	MyGrid.info.origin.orientation.w = 0.0;
// 	MyGrid.info.width = 100;
// 	MyGrid.info.height = 100;
// 	MyGrid.info.map_load_time = ros::Time::now();

// 	bool b= true;
// 	int xcvb = 0;
// 	for(int i=0;i<100;i++)
// 	{
// 		for(int j=0;j<100;j++)
// 		{
// 			b = true;
// 			for(int k=0; k<s; k++)
// 			{
// 				if(i> arr[k][0] && i<arr[k][1] && j> arr[k][2] && j< arr[k][3])
// 				{
// 					xcvb++;
// 					MyGrid.data.push_back(100);
// 					b= false;
// 					break;
// 				}
// 			}
// 			if(b)
// 			{
// 				xcvb++;
// 				MyGrid.data.push_back(0);
// 			}
// 		}
// 	}
// 	cout<<xcvb<<" asd"<<endl;
// 	 while (ros::ok())
// 	 {
// 	 	poses.poses.clear();
// 		cout<<count<<endl;

// 		for(int i=0; i<Path.size(); i++)
// 		{
// 			geometry_msgs::PoseStamped vertex;
// 			vertex.pose.position.x= Path[i].x;
// 			vertex.pose.position.y= Path[i].y;
// 			vertex.pose.position.z= 0;

		

		
// 			poses.poses.push_back(vertex);
// 		}

// 		chatter_pub.publish(poses);
// 		map_pub.publish(MyGrid);

//     ros::spinOnce();

//     loop_rate.sleep();

//     	count++;
		
// 	 }
  

// 	return 0;
// }







// #include<iostream>
// #include<vector>
// #include<stdlib.h>
// #include<time.h>
// #include<math.h>
// #include "ros/ros.h"
//  #include "std_msgs/Header.h"
// #include "geometry_msgs/Pose.h"
// #include "nav_msgs/MapMetaData.h"
// #include "nav_msgs/OccupancyGrid.h"
// #include "nav_msgs/Path.h"
// // #include <typeinfo>
// using namespace std;


// float stepsize= 3;
// float radius= 10;
// float goal_radius= 4;
// int RoadMapW, RoadMapH;

// float arr[2][4]= {{20, 60, 20, 50}, {50, 80, 50, 80}};
// int s= sizeof(arr)/sizeof(arr[0]);


// struct Point
// {
// 	double x;
// 	double y;
// };

// struct Node
// {

// 	float cost;
// 	Point P; 
// 	Node *parent;

// };

// const int goalx = 95;
// const int goaly = 95;
// const int begx = 1;
// const int begy = 1;

// const int gridx = 100;
// const int gridy = 100;

// Point gridSize = {gridx, gridy};

// Point goal= {goalx, goaly};
// Point beg= {begx, begy};

// //int arr_1[gridx][gridy];
// vector<vector<int>> obstacle_map;

// /*for(int i=0; i<abs(goal.x-beg.x+1); i++)
// 	for(int j=0; j<abs(goal.y-beg.y+1))
// 		arr_1[i][j]= 0;
// for(int i=0; i<s; i++)
// {
// 	for(int j=arr[i][0]; j<=arr[i][1]; j++)
// 		for(int k=arr[i][2]; k<=arr[i][3]; j++)
// 			arr_1[i][j]= 1;
// }*/



// // Point x_centre= {(goal.x+beg.x)/2, (goal.y+beg.y)/2};


// // float c_min= sqrt((goal.x-beg.x)*(goal.x-beg.x) + (goal.y-beg.y)*(goal.y-beg.y));
// // float C[2][2]= {{(goal.x-beg.x)/c_min, (goal.x-beg.x)/c_min}, {(goal.y-beg.y)/c_min, (goal.y-beg.y)/c_min}} ;


// class RRT
// {
// public:
// 	Node* start = new Node;
// 	// start = &dd;
// 	vector<Node*> all_nodes;
// 	Node* final = new Node;
// 	Node sstart;
// 	RRT()
// 	{
		
		
// 		//cout<<"aa "<<(*start).P.x<<endl;
// 		//cout<<start->P.x<<endl;
		
// 		//cout<<sstart.P.x<<endl;
// 		(*start).P.x = beg.x;
		
// 		(*start).P.y = beg.y;
		
// 		start->parent= NULL;
		
// 		start->cost= 0;
		
// 		all_nodes.push_back(start);
		
// 		final->parent= NULL;
		
// 	}
// 	Node* generate_randnode()
// 	{
// 		// rand();
// 		// int asdfghjkhgfdsa = 1;
// 		Point p= {(rand() % int(gridSize.x+0)) +0, ((rand() % int(gridSize.y+0)))+0};
// 		bool a= true;
// 		/*cout<<"sssssss"<<endl;
// 		for(int i= 0; i< all_nodes.size(); i++)
// 		{
// 			//cout<<"sssssss"<<endl;
// 			if(((p.x= (all_nodes[i]->P).x) && (p.y= (all_nodes[i]->P).y)))
// 				a= false;
				
// 		}*/
// 		if(a)
// 		{
// 			Node* rand_node= new Node;
// 			rand_node-> P= p;
// 			rand_node-> parent= NULL;
// 			rand_node->cost= 0;
// 			return rand_node;
// 		}
// 		else
// 			generate_randnode();
// 	}
		


// 	/*float** multiply_matrices(float a[2][2], float b[2][2])
// 	{
// 		// float** c;
// 		float** c= new float*[2];
// 		c[0]= new float[2];
// 		c[1]= new float[2];
// 		c[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
// 		c[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];
// 		c[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
// 		c[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
// 		return c;
// 	}
// 	float* multiply_matr_vec(float a[2][2], float b[2])
// 	{
// 		float c_1[2];
// 		c_1[0]= a[0][0]*b[0] + a[0][1]*b[1];
// 		c_1[1]= a[1][0]*b[0] + a[1][1]*b[1];
// 		return c_1;
// 	}
// 	Node* sample(float c_best)
// 	{
// 		float r= (float) rand()/RAND_MAX;
// 		float theta= (float) rand()/RAND_MAX* 2*22/7;
// 		float s_1[2];
// 		s_1[0]= r*cos(theta);
// 		s_1[1]= r*sin(theta);
// 		float L[2][2]= {{0,0}, {0,0}};
// 		L[0][0]= c_best/2;
// 		L[1][1]= 0.5*sqrt(c_best*c_best - c_min*c_min);
// 		float** k=multiply_matrices(C, L);
		
// 		float* p= multiply_matr_vec(&&k, s_1);
// 		Point n;
// 		n.x= p[0]+x_centre.x;
// 		n.y= p[1]+x_centre.y;
// 		Node* rand_1;
// 		rand_1->P= n;
// 		if((obstacle_check(rand_1)) && n.x<= gridSize.x && n.y<= gridSize.y)
// 		{
// 			rand_1->parent= NULL;
// 			return rand_1;
// 		}
// 		else
// 			sample(c_best);
// 	}*/

// 	vector<Node*> near_nodes(Node* N)
// 	{
// 		//cout<<12345<<endl;
// 		vector<Node*> nearby_nodes;
// 		int e=1;
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			if(distance(all_nodes[i]->P, N->P)< radius)
// 			{
// 				// cout<<"boom "<<all_nodes[i]->P.x<<" "<<all_nodes[i]->P.y<<endl;
// 				nearby_nodes.push_back(all_nodes[i]);
// 			}
// 			if(all_nodes[i]==N)
// 			{
// 				//cout<<i;
// 				e=i;
// 			}
// 		}
// 		//cout<<endl<<3<<endl;
// 		//nearby_nodes.erase(nearby_nodes.begin()+ e);
// 		//cout<<nearby_nodes.size()<<endl<<"11236432875260746597284343798247897432894890952"<<endl;
// 		return nearby_nodes;
// 	}



// 	// bool obstacle_check_1(Node* N)
// 	// {
// 	// 	Point p= N->P;
// 	// 	int a, b;
// 	// 	a= p.x;
// 	// 	b= p.y;
// 	// 	int bb = 1, aa = 1;
// 	// 	if(b>99)
// 	// 	{
// 	// 		b = 99;
// 	// 	}
// 	// 	for(int i=0; i<s; i++)
// 	// 	{
// 	// 		if((p.x>=(arr[i][0]-0)&&p.x<=(arr[i][1]+0)) && (p.y>=(arr[i][2]-0)&&p.y<=(arr[i][3]+0)))
// 	// 		{
// 	// 			bb = 0;
// 	// 			// return false;
// 	// 		}
// 	// 	}
// 	// 	if(arr_1[a][b]==1)
// 	// 	{
// 	// 		aa = 0;
// 	// 	}
// 	// 	if(aa!=bb)
// 	// 	{

// 	// 		cout<<"booooooom "<<aa<<bb<<endl;
// 	// 	}
// 	// 	if(!(a<100 and a>=0 && b>=0 && b<100))
// 	// 	{
// 	// 		cout<<"asdfghj "<<a<<" "<<b<<"\n";
// 	// 	}
// 	// 	return bb;
// 	// }

// 	// bool obstacle_check_2(Node* N)
// 	// {
// 	// 	Point p= N->P;
// 	// 	for(int i=0; i<s; i++)
// 	// 	{
// 	// 		if((p.x>=(arr[i][0]-1)&&p.x<=(arr[i][1]+1)) && (p.y>=(arr[i][2]-1)&&p.y<=(arr[i][3]+1)))
// 	// 			return false;
// 	// 	}
// 	// 	return true;
// 	// }

// 	bool obstacle_check(Node* N)
// 	{
// 		Point p= N->P;
// 		int a, b;
// 		a= p.x;
// 		b= p.y;
// 		if(obstacle_map[a][b]==1)
// 			return false;
// 		return true;
// 	}


// 	bool linejoin_check(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		Node* N_1= new Node;
// 		Node* N_2= new Node;
// 		Node* N_3= new Node;
// 		Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
// 		Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
// 		Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
// 		N_1->P= n_1;
// 		N_2->P= n_2;
// 		N_3->P= n_3;
// 		if(!(obstacle_check(N_1)))
// 			return 0;
// 		else if(!(obstacle_check(N_2)))
// 			return 0;
// 		else if(!(obstacle_check(N_3)))
// 			return 0;
// 		else
// 			return 1;
// 	}


// 	Node* nearest_node(Node* N)
// 	{
// 		Node* nearest= new Node;
// 		float d= 1000000;
// 		float m;
// 		//vector<Node*> all_= near_nodes(N);

// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			m= distance(all_nodes[i]->P, N->P);
// 			if(m<d)
// 			{
// 				d= m;
// 				nearest= all_nodes[i];
// 			}	
// 		}
// 		return nearest;
// 	}


// 	Node* new_node(Node* nearest, Node* N)
// 	{
// 		Node* new_node= new Node;
// 		float s= stepsize;
// 		Point m;
// 		//cout<<distance(nearest->P, N->P)<<endl;
// 		if(linejoin_check(nearest, N))
// 		{
// 			if((distance(N->P, nearest->P)< s))
// 			{
// 				new_node->P= N->P;
// 				new_node->cost= nearest->cost+ distance(N->P, nearest->P);
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 			else
// 			{
// 				m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
// 				m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 				new_node->P= m;
// 				new_node->cost= nearest->cost + s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 		}
// 		//cout<<nearest->P.x<<endl<<nearest->P.y<<endl;
// 		//cout<<"00000000000000"<<endl<<m.x<<endl<<m.y<<endl;
// 		int a= 1;
			



// 		while(a && s> 0.01*stepsize)
// 		{
// 			if(!obstacle_check(new_node))
// 			{
				

// 				(new_node->P).x= 0.9*(new_node->P).x+ 0.1*(nearest->P).x;
// 				(new_node->P).y= 0.9*(new_node->P).y+ 0.1*(nearest->P).y;
// 				s*= 0.9;   
// 				//cout<<new_node->P.x<<endl<<new_node->P.y<<endl<<endl;
// 			}
// 			else
// 			{
// 				a= 0;
// 				new_node->cost= nearest->cost+ s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}

// 		}






// 		/*if(a==0)
// 		{
// 			new_node->cost= nearest->cost+ s;
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}*/

// 			//cout<<a<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
// 			return NULL;
		
// 	}


// 	float distance(Point a, Point b)
// 	{
// 		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
// 	}




// 	Node* best_parent(Node* N)
// 	{
// 		vector<Node*> q= near_nodes(N);
// 		//cout<<"6666666666"<<q.size()<<endl;
// 		Node* best= new Node;
// 		best->cost = 10000000;
// 		float best_cost = best->cost;
// 		float now_cost = best->cost;
// 		// cout<<"innnnnnnnnnnnnnn"<<endl;
// 		for(int i= 0; i<q.size(); i++)
// 		{
// 			//cout<<"cost"<<" "<<q[i]->cost<<endl;
// 			if(!(q[i]== N))
// 			{
// 				//cout<<"shoot "<<q[i]->cost<<endl;
// 				//+ distance(q[i]->P, N->P)
// 				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
// 				if(now_cost < best_cost)
// 				{
// 					//cout<<"in here"<<q[i]->P.x<<" "<<q[i]->P.y<<" "<<linejoin_check(q[i], N)<<endl;
					
// 					if((linejoin_check(q[i], N)))
// 					{
// 						best= q[i];
// 						// cout<<"asdfghjkl"<<endl;
// 						best_cost = now_cost;
// 						// best->cost = best_cost;
// 					}
// 				}
// 			}
// 		}
// 		// cout<<"fu"<<endl;
// 		if(!(q.size()==1))
// 		{
// 			// cout<<"in here"<<best->P.x<<" "<<best->P.y<<endl;
// 			// cout<<"8888888888888"<<endl;
// 			N->cost= best_cost;
// 			N->parent= best;
// 			return best;
// 		}
// 		else
// 		{
// 			// cout<<"1111111111111"<<endl;
// 			return N->parent;
// 		}	
// 	}

// 	void rewire(Node* N)
// 	{
// 		vector<Node*> w= near_nodes(N);


// 		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
// 			w.push_back(final);
// 		//cout<<w.size();
// 		Node* bestparent_n= best_parent(N);


// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if(bestparent_n== w[i])
// 			{
// 				w.erase(w.begin()+ i);
// 				break;
// 			}
			
// 		}


		
// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost)
// 			{
				

// 				//cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
// 				if((linejoin_check(N, w[i])))
// 				{
// 					w[i]->parent= N;
// 					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
// 				}

// 			}
// 		}

// 	}

// 	bool goal_check(Node* N, Point goal)
// 	{
// 		if(distance(N->P, goal) < goal_radius)
// 		{
// 			final->parent= N;
// 			final->P= goal;
// 			final->cost= N->cost+ distance(N->P, goal);
// 			return true;
// 		}
// 		return false;
// 	}

// 	vector<Node*> shortest_path(Node* start, Node* final)
// 	{
// 		vector<Node*> path;
		
// 		Node* a= final;
// 		int i=1;
// 			while(!(a->parent== NULL))
// 			{
// 				//cout<<i<<endl;

// 				path.push_back(a);
				
// 				//cout<<path.size()<<endl;
// 				if((a->parent==start))
// 					path.push_back(start);
// 				a= a->parent;
				
// 				i++;
				
// 			}
			
			
// 			//path.push_back(start->P);
// 		return path;
// 	}


// };



// vector<Node*> find_path()
// {
// 	RRT rrt;	
// 	bool c= 0;

// 	int iter_max= 4000;
// 	vector<Node*> Path_nodes;
// 	vector<Point> random_nodes;
// 	Node* rand_n= new Node;
// 	Node* nearest_1= new Node;
// 	Node* new_n= new Node;

// 	int check= 1;


// 	for(int i= 1; i<iter_max; i++)
// 	{
		


// 		rand_n= rrt.generate_randnode();
// 		random_nodes.push_back(rand_n->P);
// 		nearest_1= rrt.nearest_node(rand_n);
		
// 		new_n= rrt.new_node(nearest_1, rand_n);
// 		if(!(new_n==NULL))
// 		{
			

// 			c= !(rrt.final->parent== NULL);
// 			//cout<<c<<endl;

// 			if(c==1)
// 			{
				
// 				rrt.best_parent(new_n);
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
				
// 				}
// 				Path_nodes= rrt.shortest_path(rrt.start, rrt.final);
				
// 			}
// 			else
// 			{
// 				rrt.best_parent(new_n);				
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
// 				}
// 			}
// 		}


		

// 	}
// 	float q= 0;

// 	vector<Point> Path;

// 	for(int i=0; i< Path_nodes.size(); i++)
// 	{
// 		Path.push_back(Path_nodes[i]->P);
// 	}

// 	 //for(int i=0;i<Path.size();i++)
// 	 //{
// 	 	//cout<<Path[i].x<< ", "<< Path[i].y<< endl;

// 	 //}

// 	// cout<<5555555<<endl;

// 	// vector<Node*> all_1= rrt.all_nodes;
	 
// 	//  cout<<rrt.linejoin_check(rrt.start, rrt.final)<<endl<<666<<endl;;

	 

// 	 // for(int i=0;i<Path.size();i++)
// 	 // {
// 	 // 	cout<<Path[i].x<< ", "<< Path[i].y<< endl<<Path_nodes[i]->cost<<endl;
// 	 // 	if(i>0)
// 	 // 		cout<<rrt.distance(Path[i], Path[i-1])<<endl<<endl;

// 	 // }

// 	  cout<<endl<<rrt.final->cost<<endl;
	 
	 
	 
	 
// 	 int s=1;
// 	 return Path_nodes;

// }



// void RoadCallback(nav_msgs::OccupancyGrid msg)
// {
// 	if(!msg.data.empty())
// 	{
		

// 		int i,j;
// 		RoadMapW = msg.info.width;
// 		RoadMapH = msg.info.height;
// 		obstacle_map.reserve(RoadMapW);
		

// 		for(i=0; i<RoadMapH; i++)//initialising map
// 		{
// 			for(j=0;j<RoadMapW; j++)
// 			{
// 				obstacle_map[j].push_back(0);
// 			}
// 		}

// 		for(i=RoadMapH-1;i>=0;i--)//putting values
// 		{
// 			for(j=0;j<RoadMapW;j++)
// 			{
// 				int i1;
// 				i1=RoadMapH-1-i;
// 				if(msg.data[i*RoadMapW+j]==2)
// 				{
// 					obstacle_map[j][i] = msg.data[i*RoadMapW+j];
// 				}
// 			}
// 		}
// 	}
// }


// int main(int argc, char **argv)
// {
// 	/*for(int i=0; i<=gridx; i++)
// 		for(int j=0; j<=gridy;j++)
// 			arr_1[i][j]= 0;

// 	for(int i=0; i<s; i++)
// 	{
// 		for(int j=arr[i][0]-1; j<arr[i][1]+1; j++)
// 		{
// 			for(int k=arr[i][2]-1; k<arr[i][3]+1; k++)
// 			{
// 				if(j>=0 and j<100 and k>=0 and k<100)
// 					arr_1[j][k]= 1;
// 			}
// 		}
// 	}*/

// 	RRT a_1;


// 	ros::init(argc, argv, "rrt");

// 	ros::NodeHandle LRSubNode;
// 	ros::Subscriber SubRoad = LRSubNode.subscribe<nav_msgs::OccupancyGrid>("/Road_Occupancy_Grid",1,RoadCallback);

// 	//cout<<2222;
// 	vector<Node*> Path_nodes= find_path();
// 	vector<Point> Path;
	
// 	for(int i=0; i< Path_nodes.size(); i++)
// 	{
// 		Path.push_back(Path_nodes[i]->P);
// 	}

// 		int count= 0;

	 

// 	 ros::NodeHandle v;
// 	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 	 ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1000);
// 	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1000);
// 	 ros::Rate loop_rate(10);

// 	nav_msgs::Path poses;
// 	poses.header.frame_id = "map";

// 	nav_msgs::OccupancyGrid MyGrid;

// 	MyGrid.header.stamp = ros::Time::now();
// 	MyGrid.header.frame_id = "map";
// 	MyGrid.info.resolution = 1.0;
// 	MyGrid.info.origin.position.x = 0.0;
// 	MyGrid.info.origin.position.y = 0.0;
// 	MyGrid.info.origin.position.z = 0.0;
// 	MyGrid.info.origin.orientation.x = 0.0;
// 	MyGrid.info.origin.orientation.y = 0.0;
// 	MyGrid.info.origin.orientation.z = 0.0;
// 	MyGrid.info.origin.orientation.w = 0.0;
// 	MyGrid.info.width = RoadMapW;
// 	MyGrid.info.height = RoadMapH;
// 	MyGrid.info.map_load_time = ros::Time::now();

// 	bool b= true;
// 	int xcvb = 0;
// 	for(int i=0;i<RoadMapW;i++)
// 	{
// 		for(int j=0;j<RoadMapH;j++)
// 		{
// 			Node* e;
// 			e->P.x= i;
// 			e->P.y= j;

// 				if(!a_1.obstacle_check(e))
// 				{
// 					xcvb++;
// 					MyGrid.data.push_back(100);
// 					break;
// 				}
			
// 			if(b)
// 			{
// 				xcvb++;
// 				MyGrid.data.push_back(0);
// 			}
// 		}
// 	}
// 	cout<<xcvb<<" asd"<<endl;
// 	 while (ros::ok())
// 	 {
// 	 	poses.poses.clear();
// 		cout<<count<<endl;

// 		for(int i=0; i<Path.size(); i++)
// 		{
// 			geometry_msgs::PoseStamped vertex;
// 			vertex.pose.position.x= Path[i].x;
// 			vertex.pose.position.y= Path[i].y;
// 			vertex.pose.position.z= 0;

		

		
// 			poses.poses.push_back(vertex);
// 		}

// 		chatter_pub.publish(poses);
// 		map_pub.publish(MyGrid);

//     ros::spinOnce();

//     loop_rate.sleep();

//     	count++;
		
// 	 }
  

// 	return 0;
// }



// #include<iostream>
// #include<vector>
// #include<stdlib.h>
// #include<time.h>
// #include<math.h>
// #include "ros/ros.h"
//  #include "std_msgs/Header.h"
// #include "geometry_msgs/Pose.h"
// #include "nav_msgs/MapMetaData.h"
// #include "nav_msgs/OccupancyGrid.h"
// #include "nav_msgs/Path.h"
// // #include <typeinfo>
// using namespace std;

// bool checkMap = false;
// float stepsize= 3;
// float radius= 10;
// float goal_radius= 4;
// int RoadMapW, RoadMapH;

// float arr[2][4]= {{20, 60, 20, 50}, {50, 80, 50, 80}};
// int s= sizeof(arr)/sizeof(arr[0]);


// struct Point
// {
// 	double x;
// 	double y;
// };

// struct Node
// {

// 	float cost;
// 	Point P; 
// 	Node *parent;

// };

// int goalx = 95;
// int goaly = 95;
// int begx = 20;
// int begy = 0;


// Point gridSize = {RoadMapW, RoadMapH};

// Point goal= {goalx, goaly};
// Point beg= {begx, begy};

// //int arr_1[gridx][gridy];
// vector<vector<int> > obstacle_map;


// //ros::init("rrt");
// ros::Publisher chatter_pub;
// nav_msgs::Path poses;


// /*for(int i=0; i<abs(goal.x-beg.x+1); i++)
// 	for(int j=0; j<abs(goal.y-beg.y+1))
// 		arr_1[i][j]= 0;
// for(int i=0; i<s; i++)
// {
// 	for(int j=arr[i][0]; j<=arr[i][1]; j++)
// 		for(int k=arr[i][2]; k<=arr[i][3]; j++)
// 			arr_1[i][j]= 1;
// }*/



// // Point x_centre= {(goal.x+beg.x)/2, (goal.y+beg.y)/2};


// // float c_min= sqrt((goal.x-beg.x)*(goal.x-beg.x) + (goal.y-beg.y)*(goal.y-beg.y));
// // float C[2][2]= {{(goal.x-beg.x)/c_min, (goal.x-beg.x)/c_min}, {(goal.y-beg.y)/c_min, (goal.y-beg.y)/c_min}} ;


// class RRT
// {
// public:
// 	Node* start = new Node;
// 	// start = &dd;
// 	vector<Node*> all_nodes;
// 	Node* final = new Node;
// 	Node sstart;
// 	RRT()
// 	{
		
		
// 		//cout<<"aa "<<(*start).P.x<<endl;
// 		//cout<<start->P.x<<endl;
		
// 		//cout<<sstart.P.x<<endl;
// 		(*start).P.x = beg.x;
		
// 		(*start).P.y = beg.y;
		
// 		start->parent= NULL;
		
// 		start->cost= 0;
		
// 		all_nodes.push_back(start);
		
// 		final->parent= NULL;
		
// 	}
// 	Node* generate_randnode()
// 	{

// 		// rand();
// 		// int asdfghjkhgfdsa = 1;
// 		Point gridSize = {RoadMapW, RoadMapH};
// 		//cout<<4444444<<endl;
// 		//cout<<gridSize.x<<","<<gridSize.y<<endl;
// 		Point p= {(rand() % int(gridSize.x)) +0, ((rand() % int(gridSize.y+0)))+0};
// 		bool a= true;
// 		//cout<<5555555<<endl;
// 		/*cout<<"sssssss"<<endl;
// 		for(int i= 0; i< all_nodes.size(); i++)
// 		{
// 			//cout<<"sssssss"<<endl;
// 			if(((p.x= (all_nodes[i]->P).x) && (p.y= (all_nodes[i]->P).y)))
// 				a= false;
				
// 		}*/
// 		if(a)
// 		{
// 			Node* rand_node= new Node;
// 			rand_node-> P= p;
// 			rand_node-> parent= NULL;
// 			rand_node->cost= 0;
// 			return rand_node;
// 		}
// 		else
// 			generate_randnode();
// 	}
		


// 	/*float** multiply_matrices(float a[2][2], float b[2][2])
// 	{
// 		// float** c;
// 		float** c= new float*[2];
// 		c[0]= new float[2];
// 		c[1]= new float[2];
// 		c[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
// 		c[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];
// 		c[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
// 		c[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
// 		return c;
// 	}
// 	float* multiply_matr_vec(float a[2][2], float b[2])
// 	{
// 		float c_1[2];
// 		c_1[0]= a[0][0]*b[0] + a[0][1]*b[1];
// 		c_1[1]= a[1][0]*b[0] + a[1][1]*b[1];
// 		return c_1;
// 	}
// 	Node* sample(float c_best)
// 	{
// 		float r= (float) rand()/RAND_MAX;
// 		float theta= (float) rand()/RAND_MAX* 2*22/7;
// 		float s_1[2];
// 		s_1[0]= r*cos(theta);
// 		s_1[1]= r*sin(theta);
// 		float L[2][2]= {{0,0}, {0,0}};
// 		L[0][0]= c_best/2;
// 		L[1][1]= 0.5*sqrt(c_best*c_best - c_min*c_min);
// 		float** k=multiply_matrices(C, L);
		
// 		float* p= multiply_matr_vec(&&k, s_1);
// 		Point n;
// 		n.x= p[0]+x_centre.x;
// 		n.y= p[1]+x_centre.y;
// 		Node* rand_1;
// 		rand_1->P= n;
// 		if((obstacle_check(rand_1)) && n.x<= gridSize.x && n.y<= gridSize.y)
// 		{
// 			rand_1->parent= NULL;
// 			return rand_1;
// 		}
// 		else
// 			sample(c_best);
// 	}*/

// 	vector<Node*> near_nodes(Node* N)
// 	{
// 		//cout<<12345<<endl;
// 		vector<Node*> nearby_nodes;
// 		int e=1;
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			if(distance(all_nodes[i]->P, N->P)< radius)
// 			{
// 				// cout<<"boom "<<all_nodes[i]->P.x<<" "<<all_nodes[i]->P.y<<endl;
// 				nearby_nodes.push_back(all_nodes[i]);
// 			}
// 			if(all_nodes[i]==N)
// 			{
// 				//cout<<i;
// 				e=i;
// 			}
// 		}
// 		//cout<<endl<<3<<endl;
// 		//nearby_nodes.erase(nearby_nodes.begin()+ e);
// 		//cout<<nearby_nodes.size()<<endl<<"11236432875260746597284343798247897432894890952"<<endl;
// 		return nearby_nodes;
// 	}



// 	// bool obstacle_check_1(Node* N)
// 	// {
// 	// 	Point p= N->P;
// 	// 	int a, b;
// 	// 	a= p.x;
// 	// 	b= p.y;
// 	// 	int bb = 1, aa = 1;
// 	// 	if(b>99)
// 	// 	{
// 	// 		b = 99;
// 	// 	}
// 	// 	for(int i=0; i<s; i++)
// 	// 	{
// 	// 		if((p.x>=(arr[i][0]-0)&&p.x<=(arr[i][1]+0)) && (p.y>=(arr[i][2]-0)&&p.y<=(arr[i][3]+0)))
// 	// 		{
// 	// 			bb = 0;
// 	// 			// return false;
// 	// 		}
// 	// 	}
// 	// 	if(arr_1[a][b]==1)
// 	// 	{
// 	// 		aa = 0;
// 	// 	}
// 	// 	if(aa!=bb)
// 	// 	{

// 	// 		cout<<"booooooom "<<aa<<bb<<endl;
// 	// 	}
// 	// 	if(!(a<100 and a>=0 && b>=0 && b<100))
// 	// 	{
// 	// 		cout<<"asdfghj "<<a<<" "<<b<<"\n";
// 	// 	}
// 	// 	return bb;
// 	// }

// 	// bool obstacle_check_2(Node* N)
// 	// {
// 	// 	Point p= N->P;
// 	// 	for(int i=0; i<s; i++)
// 	// 	{
// 	// 		if((p.x>=(arr[i][0]-1)&&p.x<=(arr[i][1]+1)) && (p.y>=(arr[i][2]-1)&&p.y<=(arr[i][3]+1)))
// 	// 			return false;
// 	// 	}
// 	// 	return true;
// 	// }

// 	bool obstacle_check(Node* N)
// 	{
// 		Point p= N->P;
// 		int a, b;
// 		a= p.x;
// 		b= p.y;
// 		if(obstacle_map[a][b]==1)
// 			return false;
// 		return true;
// 	}


// 	bool linejoin_check(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		Node* N_1= new Node;
// 		Node* N_2= new Node;
// 		Node* N_3= new Node;
// 		Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
// 		Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
// 		Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
// 		N_1->P= n_1;
// 		N_2->P= n_2;
// 		N_3->P= n_3;
// 		if(!(obstacle_check(N_1)))
// 			return 0;
// 		else if(!(obstacle_check(N_2)))
// 			return 0;
// 		else if(!(obstacle_check(N_3)))
// 			return 0;
// 		else
// 			return 1;
// 	}


// 	Node* nearest_node(Node* N)
// 	{
// 		Node* nearest= new Node;
// 		float d= 1000000;
// 		float m;
// 		//vector<Node*> all_= near_nodes(N);

// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			m= distance(all_nodes[i]->P, N->P);
// 			if(m<d)
// 			{
// 				d= m;
// 				nearest= all_nodes[i];
// 			}	
// 		}
// 		return nearest;
// 	}


// 	Node* new_node(Node* nearest, Node* N)
// 	{
// 		Node* new_node= new Node;
// 		float s= stepsize;
// 		Point m;
// 		//cout<<distance(nearest->P, N->P)<<endl;
// 		if(linejoin_check(nearest, N))
// 		{
// 			if((distance(N->P, nearest->P)< s))
// 			{
// 				new_node->P= N->P;
// 				new_node->cost= nearest->cost+ distance(N->P, nearest->P);
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 			else
// 			{
// 				m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
// 				m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 				new_node->P= m;
// 				new_node->cost= nearest->cost + s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 		}
// 		//cout<<nearest->P.x<<endl<<nearest->P.y<<endl;
// 		//cout<<"00000000000000"<<endl<<m.x<<endl<<m.y<<endl;
// 		int a= 1;
			



// 		/*while(a && s> 0.01*stepsize)
// 		{
// 			if(!obstacle_check(new_node))
// 			{
				
// 				(new_node->P).x= 0.9*(new_node->P).x+ 0.1*(nearest->P).x;
// 				(new_node->P).y= 0.9*(new_node->P).y+ 0.1*(nearest->P).y;
// 				s*= 0.9;   
// 				//cout<<new_node->P.x<<endl<<new_node->P.y<<endl<<endl;
// 			}
// 			else
// 			{
// 				a= 0;
// 				new_node->cost= nearest->cost+ s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 		}*/






// 		/*if(a==0)
// 		{
// 			new_node->cost= nearest->cost+ s;
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}*/

// 			//cout<<a<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
// 			return NULL;
		
// 	}


// 	float distance(Point a, Point b)
// 	{
// 		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
// 	}




// 	Node* best_parent(Node* N)
// 	{
// 		vector<Node*> q= near_nodes(N);
// 		//cout<<"6666666666"<<q.size()<<endl;
// 		Node* best= new Node;
// 		best->cost = 10000000;
// 		float best_cost = best->cost;
// 		float now_cost = best->cost;
// 		// cout<<"innnnnnnnnnnnnnn"<<endl;
// 		for(int i= 0; i<q.size(); i++)
// 		{
// 			//cout<<"cost"<<" "<<q[i]->cost<<endl;
// 			if(!(q[i]== N))
// 			{
// 				//cout<<"shoot "<<q[i]->cost<<endl;
// 				//+ distance(q[i]->P, N->P)
// 				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
// 				if(now_cost < best_cost)
// 				{
// 					//cout<<"in here"<<q[i]->P.x<<" "<<q[i]->P.y<<" "<<linejoin_check(q[i], N)<<endl;
					
// 					if((linejoin_check(q[i], N)))
// 					{
// 						best= q[i];
// 						// cout<<"asdfghjkl"<<endl;
// 						best_cost = now_cost;
// 						// best->cost = best_cost;
// 					}
// 				}
// 			}
// 		}
// 		// cout<<"fu"<<endl;
// 		if(!(q.size()==1))
// 		{
// 			// cout<<"in here"<<best->P.x<<" "<<best->P.y<<endl;
// 			// cout<<"8888888888888"<<endl;
// 			N->cost= best_cost;
// 			N->parent= best;
// 			return best;
// 		}
// 		else
// 		{
// 			// cout<<"1111111111111"<<endl;
// 			return N->parent;
// 		}	
// 	}

// 	void rewire(Node* N)
// 	{
// 		vector<Node*> w= near_nodes(N);


// 		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
// 			w.push_back(final);
// 		//cout<<w.size();
// 		Node* bestparent_n= best_parent(N);


// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if(bestparent_n== w[i])
// 			{
// 				w.erase(w.begin()+ i);
// 				break;
// 			}
			
// 		}


		
// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost)
// 			{
				

// 				//cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
// 				if((linejoin_check(N, w[i])))
// 				{
// 					w[i]->parent= N;
// 					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
// 				}

// 			}
// 		}

// 	}

// 	bool goal_check(Node* N, Point goal)
// 	{
// 		if(distance(N->P, goal) < goal_radius)
// 		{
// 			final->parent= N;
// 			final->P= goal;
// 			final->cost= N->cost+ distance(N->P, goal);
// 			return true;
// 		}
// 		return false;
// 	}

// 	vector<Node*> shortest_path(Node* start, Node* final)
// 	{
// 		vector<Node*> path;
		
// 		Node* a= final;
// 		int i=1;
// 			while(!(a->parent== NULL))
// 			{
// 				//cout<<i<<endl;

// 				path.push_back(a);
				
// 				//cout<<path.size()<<endl;
// 				if((a->parent==start))
// 					path.push_back(start);
// 				a= a->parent;
				
// 				i++;
				
// 			}
			
			
// 			//path.push_back(start->P);
// 		return path;
// 	}


// };



// vector<Node*> find_path()
// {
// 	//cout<<3333333333333<<endl;
// 	RRT rrt;	
// 	bool c= 0;

// 	int iter_max= 3000;
// 	vector<Node*> Path_nodes;
// 	vector<Point> random_nodes;
// 	Node* rand_n= new Node;
// 	Node* nearest_1= new Node;
// 	Node* new_n= new Node;

// 	int check= 1;


// 	for(int i= 1; i<iter_max; i++)
// 	{
		
// 		//cout<<333333333564333<<endl;

// 		rand_n= rrt.generate_randnode();
// 		//cout<<3333333333333<<endl;
// 		random_nodes.push_back(rand_n->P);
// 		nearest_1= rrt.nearest_node(rand_n);
		
// 		new_n= rrt.new_node(nearest_1, rand_n);
// 		if(!(new_n==NULL))
// 		{
			

// 			c= !(rrt.final->parent== NULL);
// 			//cout<<c<<endl;

// 			if(c==1)
// 			{
				
// 				rrt.best_parent(new_n);
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
				
// 				}
// 				Path_nodes= rrt.shortest_path(rrt.start, rrt.final);
				
// 			}
// 			else
// 			{
// 				rrt.best_parent(new_n);				
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
// 				}
// 			}
// 		}


		

// 	}
// 	float q= 0;

// 	vector<Point> Path;

// 	for(int i=0; i< Path_nodes.size(); i++)
// 	{
// 		Path.push_back(Path_nodes[i]->P);
// 	}

// 	 //for(int i=0;i<Path.size();i++)
// 	 //{
// 	 	//cout<<Path[i].x<< ", "<< Path[i].y<< endl;

// 	 //}

// 	// cout<<5555555<<endl;

// 	// vector<Node*> all_1= rrt.all_nodes;
	 
// 	//  cout<<rrt.linejoin_check(rrt.start, rrt.final)<<endl<<666<<endl;;

	 

// 	 // for(int i=0;i<Path.size();i++)
// 	 // {
// 	 // 	cout<<Path[i].x<< ", "<< Path[i].y<< endl<<Path_nodes[i]->cost<<endl;
// 	 // 	if(i>0)
// 	 // 		cout<<rrt.distance(Path[i], Path[i-1])<<endl<<endl;

// 	 // }

// 	  cout<<endl<<rrt.final->cost<<endl;
	 
	 
	 
	 
// 	 int s=1;
// 	 return Path_nodes;

// }


// void publisher(vector<Point> Path, ros::Publisher chatter_pub, nav_msgs::Path poses)
// {
	
// 	RRT a_1;
	
		  
// 		  	// nav_msgs::OccupancyGrid MyGrid;
		  
// 		  	// MyGrid.header.stamp = ros::Time::now();
// 		  	// MyGrid.header.frame_id = "map";
// 		  	// MyGrid.info.resolution = 1.0;
// 		  	// MyGrid.info.origin.position.x = 0.0;
// 		  	// MyGrid.info.origin.position.y = 0.0;
// 		  	// MyGrid.info.origin.position.z = 0.0;
// 		  	// MyGrid.info.origin.orientation.x = 0.0;
// 		  	// MyGrid.info.origin.orientation.y = 0.0;
// 		  	// MyGrid.info.origin.orientation.z = 0.0;
// 		  	// MyGrid.info.origin.orientation.w = 0.0;
// 		  	// MyGrid.info.width = RoadMapW;
// 		  	// MyGrid.info.height = RoadMapH;
// 		  	// MyGrid.info.map_load_time = ros::Time::now();
		  


// 		  	// bool b= true;
// 		  	// // int xcvb = 0;
// 		  	// for(int i=0;i<RoadMapW;i++)
// 		  	// {
// 		  	// 	for(int j=0;j<RoadMapH;j++)
// 		  	// 	{

// 		  	// 		Node* e = new Node;
// 		  	// 		//cout<<"$$$$"<<endl;
// 		  	// 		Point abc = {i, j};
// 		  	// 		e->P.x= i;
// 		  	// 		e->P.y= j;
// 		  	// 		//cout<<99999<<endl;
		  
// 		  	// 			if(!a_1.obstacle_check(e))
// 		  	// 			{
// 		  	// 				// xcvb++;
// 		  	// 				MyGrid.data.push_back(100);
// 		  	// 				break;
// 		  	// 			}
		  			
// 		  	// 		if(b)
// 		  	// 		{
// 		  	// 			// xcvb++;
// 		  	// 			MyGrid.data.push_back(0);
// 		  	// 		}
// 		  	// 	}
// 		  	// }



// 		  	// cout<<xcvb<<" asd"<<endl;
// 		  	 // while (ros::ok())
// 		  	 {
// 		  	 	poses.poses.clear();
// 		  		// cout<<count<<endl;
		  
// 		  		for(int i=0; i<Path.size(); i++)
// 		  		{
// 		  			geometry_msgs::PoseStamped vertex;
// 		  			vertex.pose.position.x= Path[i].x;
// 		  			vertex.pose.position.y= Path[i].y;
// 		  			vertex.pose.position.z= 0;
		  
		  		
		  
		  		
// 		  			poses.poses.push_back(vertex);
// 		  		}
		  
// 		  		chatter_pub.publish(poses);
// 		  		//map_pub.publish(MyGrid);
		  
		  
// 		      	//count++;
		  		
// 		  	 }  
// }



// void RoadCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
// {
// 	//cout<<666666<<endl;
// 	if(!msg->data.empty())
// 	{
// 		checkMap = true;

// 		int i,j;
// 		RoadMapW = msg->info.width;
// 		RoadMapH = msg->info.height;
// 		begx = RoadMapW/2;
// 		begy = 0;
// 		goalx = 20;
// 		goaly = 20;

// 		std::vector<int> v;
// 		for (i=0; i<RoadMapW; i++) v.push_back(0);
// 		for (i=0; i<RoadMapH; i++) obstacle_map.push_back(v);

// 			//cout << "2\n";

// 		for(i=RoadMapH-1;i>=0;i--)//putting values
// 		{
// 			for(j=0;j<RoadMapW;j++)
// 			{
// 				// int i1;
// 				// i1=RoadMapH-1-i;
// 				if(msg->data[i*RoadMapW+j]==2)
// 				{
// 					obstacle_map[j][i] = msg->data[i*RoadMapW+j];
// 				}
// 			}
// 		}

// 		vector<Point> Path;
//  	//cout<<"###"<<checkMap<<endl;

  
// 	if(checkMap == true )
// 		{

// 		  	//cout<<2222;
// 		  	vector<Node*> Path_nodes= find_path();
// 		  	//cout<<"%%%%%%%%%%%%%%%%%"<<endl;
// 		  	//cout<<555<<endl<<Path_nodes.size()<<endl;
		  	
// 		  	for(int i=0; i< Path_nodes.size(); i++)
// 		  	{
// 		  		Path.push_back(Path_nodes[i]->P);
// 		  	}
// 		}

		 


// 		  publisher(Path, chatter_pub, poses);
	

// 		//cout<<RoadMapW<<","<<RoadMapH<<endl<<endl;
// 		//cout << "3\n";
// 	}
// }






// int main(int argc, char **argv)
// {
// 	/*for(int i=0; i<=gridx; i++)
// 		for(int j=0; j<=gridy;j++)
// 			arr_1[i][j]= 0;
// 	for(int i=0; i<s; i++)
// 	{
// 		for(int j=arr[i][0]-1; j<arr[i][1]+1; j++)
// 		{
// 			for(int k=arr[i][2]-1; k<arr[i][3]+1; k++)
// 			{
// 				if(j>=0 and j<100 and k>=0 and k<100)
// 					arr_1[j][k]= 1;
// 			}
// 		}
// 	}*/

// 	RRT a_1;

// 	//cout<<checkMap<<endl;
// 	ros::init(argc, argv, "rrt");

// 	ros::NodeHandle LRSubNode;
// 	ros::Subscriber SubRoad = LRSubNode.subscribe<nav_msgs::OccupancyGrid>("occ_map", 1, RoadCallback);

	
//  //  	vector<Point> Path;
//  // 	//cout<<"###"<<checkMap<<endl;
  
// 	// if(checkMap == true )
// 	// 	{
// 	// 	  	//cout<<2222;
// 	// 	  	vector<Node*> Path_nodes= find_path();
// 	// 	  	//cout<<555<<endl<<Path_nodes.size()<<endl;
		  	
// 	// 	  	for(int i=0; i< Path_nodes.size(); i++)
// 	// 	  	{
// 	// 	  		Path.push_back(Path_nodes[i]->P);
// 	// 	  	}
// 	// 	  }
// 	// 	  		int count= 0;
		  
		  	 
// 		ros::NodeHandle v;
// 		  	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 		  	 chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1);
// 		  	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1);
// 		  	 poses.header.frame_id = "map";
		  
		  	

		  
// 	 	  	 //ros::NodeHandle v;
// 	// 	  	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 	// 	  	 ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1);
// 	// 	  	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1);
		  
// 	// 	  	nav_msgs::Path poses;
// 	// 	  	poses.header.frame_id = "map";
		  
// 	// 	  	nav_msgs::OccupancyGrid MyGrid;
		  
// 	// 	  	MyGrid.header.stamp = ros::Time::now();
// 	// 	  	MyGrid.header.frame_id = "map";
// 	// 	  	MyGrid.info.resolution = 1.0;
// 	// 	  	MyGrid.info.origin.position.x = 0.0;
// 	// 	  	MyGrid.info.origin.position.y = 0.0;
// 	// 	  	MyGrid.info.origin.position.z = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.x = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.y = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.z = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.w = 0.0;
// 	// 	  	MyGrid.info.width = RoadMapW;
// 	// 	  	MyGrid.info.height = RoadMapH;
// 	// 	  	MyGrid.info.map_load_time = ros::Time::now();
		  
// 	// 	  	bool b= true;
// 	// 	  	// int xcvb = 0;
// 	// 	  	for(int i=0;i<RoadMapW;i++)
// 	// 	  	{
// 	// 	  		for(int j=0;j<RoadMapH;j++)
// 	// 	  		{
// 	// 	  			Node* e;
// 	// 	  			e->P.x= i;
// 	// 	  			e->P.y= j;
		  
// 	// 	  				if(!a_1.obstacle_check(e))
// 	// 	  				{
// 	// 	  					// xcvb++;
// 	// 	  					MyGrid.data.push_back(100);
// 	// 	  					break;
// 	// 	  				}
		  			
// 	// 	  			if(b)
// 	// 	  			{
// 	// 	  				// xcvb++;
// 	// 	  				MyGrid.data.push_back(0);
// 	// 	  			}
// 	// 	  		}
// 	// 	  	}
// 	// 	  	// cout<<xcvb<<" asd"<<endl;
// 	// 	  	 // while (ros::ok())
// 	// 	  	 {
// 	// 	  	 	poses.poses.clear();
// 	// 	  		 cout<<count<<endl;
		  
// 	// 	  		for(int i=0; i<Path.size(); i++)
// 	// 	  		{
// 	// 	  			geometry_msgs::PoseStamped vertex;
// 	// 	  			vertex.pose.position.x= Path[i].x;
// 	// 	  			vertex.pose.position.y= Path[i].y;
// 	// 	  			vertex.pose.position.z= 0;
		  
		  		
		  
		  		
// 	// 	  			poses.poses.push_back(vertex);
// 	// 	  		}
		  
// 	// 	  		chatter_pub.publish(poses);
// 	// 	  		map_pub.publish(MyGrid);
		  
		  
// 	// 	      	count++;
		  		
// 	// 	  	 }  
		  	 
// 				ros::Rate loop_rate(10);
// 				ros::spin();
		  
// 				loop_rate.sleep();

// 	return 0;
// }






























// #include<iostream>
// #include<vector>
// #include<stdlib.h>
// #include<time.h>
// #include<math.h>
// #include "ros/ros.h"
//  #include "std_msgs/Header.h"
// #include "geometry_msgs/Pose.h"
// #include "nav_msgs/MapMetaData.h"
// #include "nav_msgs/OccupancyGrid.h"
// #include "nav_msgs/Path.h"
// using namespace std;

// bool checkMap = false;
// float stepsize= 1;
// float radius= 6;
// float goal_radius= 4;
// int RoadMapW, RoadMapH;
// ros::Publisher chatter_pub;

// float arr[2][4]= {{20, 60, 20, 50}, {50, 80, 50, 80}};
// int s= sizeof(arr)/sizeof(arr[0]);


// struct Point
// {
// 	double x;
// 	double y;
// };

// struct Node
// {

// 	float cost;
// 	Point P; 
// 	Node *parent;

// };

// int goalx = 5;
// int goaly = 35;
// int begx = 20;
// int begy = 0;


// Point gridSize = {RoadMapW, RoadMapH};

// Point goal= {goalx, goaly};
// Point beg= {begx, begy};

// vector<vector<int> > obstacle_map;



// class RRT
// {
// public:
// 	Node* start = new Node;
// 	vector<Node*> all_nodes;
// 	Node* final = new Node;
// 	Node sstart;
// 	RRT()
// 	{
// 		(*start).P.x = beg.x;
		
// 		(*start).P.y = beg.y;
		
// 		start->parent= NULL;
		
// 		start->cost= 0;
		
// 		all_nodes.push_back(start);
		
// 		final->parent= NULL;
		
// 	}
// 	Node* generate_randnode()
// 	{


// 		Point gridSize = {RoadMapW, RoadMapH};
// 		Point p= {(rand() % int(gridSize.x)) +0, ((rand() % int(gridSize.y+0)))+0};
// 		bool a= true;
		
// 		Node* rand_node= new Node;
// 		rand_node-> P= p;
// 		if(!obstacle_check(rand_node))
// 			a= false;
// 		if(a)
// 		{
			
// 			rand_node-> parent= NULL;
// 			rand_node->cost= 0;
// 			return rand_node;
// 		}
// 		else
// 			generate_randnode();
// 	}
		


	

// 	vector<Node*> near_nodes(Node* N)
// 	{
// 		vector<Node*> nearby_nodes;
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			if(distance(all_nodes[i]->P, N->P)< radius)
// 			{
// 				nearby_nodes.push_back(all_nodes[i]);
// 			}
			
// 		}
// 		return nearby_nodes;
// 	}



	

// 	bool obstacle_check(Node* N)
// 	{
// 		Point p= N->P;
// 		int a, b;
// 		a= p.x;
// 		b= p.y;

// 		if(obstacle_map[a][b]>=40)
// 		{
// 			return false;
// 		}
// 		return true;
// 	}


// 	bool linejoin_check1(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		Node* N_1= new Node;
// 		Node* N_2= new Node;
// 		Node* N_3= new Node;
// 		Node* N_4= new Node;
// 		Node* N_5= new Node;
// 		Node* N_6= new Node;
// 		Node* N_7= new Node;
// 		Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
// 		Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
// 		Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
// 		Point n_4= {0.5*(n_2.x+A.x), 0.5*(n_2.y+A.y)};
// 		Point n_5= {0.5*(n_2.x+n_1.x), 0.5*(n_2.y+n_1.y)};
// 		Point n_6= {0.5*(n_3.x+n_1.x), 0.5*(n_3.y+n_1.y)};
// 		Point n_7= {0.5*(B.x+n_3.x), 0.5*(B.y+n_3.y)};
// 		N_1->P= n_1;
// 		N_2->P= n_2;
// 		N_3->P= n_3;
// 		N_4->P= n_4;
// 		N_5->P= n_5;
// 		N_6->P= n_6;
// 		N_7->P= n_7;
// 		if(!(obstacle_check(N_1)))
// 		{
// 			return 0;
// 		}
// 		else if(!(obstacle_check(N_2)))
// 		{
// 			return 0;
// 		}
// 		else if(!(obstacle_check(N_3)))
// 		{
// 			return 0;
// 		}
// 		else if(!(obstacle_check(N_4)))
// 		{
// 			return 0;
// 		}
// 		else if(!(obstacle_check(N_5)))
// 		{
// 			return 0;
// 		}
// 		else if(!(obstacle_check(N_6)))
// 		{
// 			return 0;
// 		}
// 		else if(!(obstacle_check(N_7)))
// 		{
// 			return 0;
// 		}

// 		else
// 			return 1;
// 	}



// 	bool linejoin_check(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		int l = 9;
// 		for (int i=1;i<l;i++)
// 		{
// 			Node* N_1= new Node;
// 			float c_z = (float)(i)/l;
// 			Point n_1= {((c_z)*A.x+(1-c_z)*B.x),((c_z)*A.y+(1-c_z)*B.y)};
// 			N_1->P= n_1;
// 			if(!(obstacle_check(N_1)))
// 				return 0;
// 		}
// 		return 1;
// 	}



// 	Node* nearest_node(Node* N)
// 	{
// 		Node* nearest= new Node;
// 		float d= 1000000;
// 		float m;
		
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			m= distance(all_nodes[i]->P, N->P);
// 			if(m<d)
// 			{
// 				d= m;
// 				nearest= all_nodes[i];
// 			}	
// 		}
// 		return nearest;
// 	}


	

// 	Node* new_node(Node* nearest, Node* N)
// 	{
// 		Node* new_node = new Node;
// 		float s = stepsize;
// 		Point m;
// 		if(linejoin_check(nearest, N))
// 		{
// 			if((distance(N->P, nearest->P)< s))
// 			{
// 				new_node->P= N->P;
// 				new_node->cost= nearest->cost+ distance(N->P, nearest->P);
// 				new_node->parent= nearest;
// 				if ((obstacle_check(new_node)))
//                 {
//                 	all_nodes.push_back(new_node);
//                     return new_node;
//                 }
//                 else 
//                 {
//                     return NULL;
//                 }
// 			}
// 			else
// 			{
// 				m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
// 				m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 				new_node->P= m;
// 				new_node->cost= nearest->cost + s;
// 				new_node->parent= nearest;
// 				if ((obstacle_check(new_node)))
//                 {
//                 	all_nodes.push_back(new_node);
//                     return new_node;
//                 }
//                 else 
//                 {
//                     return NULL;
//                 }
// 			}
// 		}
//         return NULL;
// 	}


// 	float distance(Point a, Point b)
// 	{
// 		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
// 	}




// 	Node* best_parent(Node* N)
// 	{
// 		vector<Node*> q= near_nodes(N);
// 		Node* best= new Node;
// 		best->cost = 10000000;
// 		float best_cost = best->cost;
// 		float now_cost = 0;
// 		for(int i= 0; i<q.size(); i++)
// 		{
// 			if(!(q[i]== N))
// 			{
// 				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
// 				if(now_cost < best_cost)
// 				{
					
// 					if((linejoin_check(q[i], N)))
// 					{
// 						best= q[i];
// 						best_cost = now_cost;
// 					}
// 				}
// 			}
// 		}
// 		if(!(q.size()==1))
// 		{
// 			N->cost= best_cost;
// 			N->parent= best;
// 			return best;
// 		}
// 		else
// 		{
// 			return N->parent;
// 		}	
// 	}

// 	void rewire(Node* N)
// 	{
// 		vector<Node*> w= near_nodes(N);


// 		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
// 			w.push_back(final);
// 		Node* bestparent_n= best_parent(N);


// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if(bestparent_n== w[i])
// 			{
// 				w.erase(w.begin()+ i);
// 				break;
// 			}
			
// 		}


		
// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost)
// 			{
				

// 				if((linejoin_check(N, w[i])))
// 				{
// 					w[i]->parent= N;
// 					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
// 				}

// 			}
// 		}

// 	}

// 	bool goal_check(Node* N, Point goal)
// 	{
// 		if(distance(N->P, goal) < goal_radius)
// 		{
// 			final->parent= N;
// 			final->P= goal;
// 			final->cost= N->cost+ distance(N->P, goal);
// 			return true;
// 		}
// 		return false;
// 	}

// 	vector<Node*> shortest_path(Node* start, Node* final)
// 	{
// 		vector<Node*> path;
		
// 		Node* a= final;
// 		int i=1;
// 			while(!(a->parent== NULL))
// 			{
	
// 				path.push_back(a);
				
// 				if((a->parent==start))
// 					path.push_back(start);
// 				a= a->parent;
				
// 				i++;
				
// 			}
			
			
// 		return path;
// 	}


// };



// vector<Node*> find_path()
// {
// 	RRT rrt;	
// 	bool c= 0;

// 	int iter_max= 5000;
// 	vector<Node*> Path_nodes;
// 	vector<Point> random_nodes;
// 	Node* rand_n= new Node;
// 	Node* nearest_1= new Node;
// 	Node* new_n= new Node;

// 	int check= 1;


// 	for(int i= 1; i<iter_max; i++)
// 	{
		
		
// 		rand_n= rrt.generate_randnode();
// 		random_nodes.push_back(rand_n->P);
// 		nearest_1= rrt.nearest_node(rand_n);
		
// 		new_n= rrt.new_node(nearest_1, rand_n);
// 		if(!(new_n==NULL))
// 		{
			

// 			c= !(rrt.final->parent== NULL);
		
// 			if(c==1)
// 			{
				
// 				rrt.best_parent(new_n);
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
				
// 				}
// 				Path_nodes= rrt.shortest_path(rrt.start, rrt.final);
				
// 			}
// 			else
// 			{
// 				rrt.best_parent(new_n);				
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
// 				}
// 			}
// 		}


		

// 	}
// 	float q= 0;

// 	vector<Point> Path;

// 	for(int i=0; i< Path_nodes.size(); i++)
// 	{
// 		Path.push_back(Path_nodes[i]->P);
// 	}

// 	  cout<<endl<<rrt.final->cost<<endl;


	 
	 
	 
// 	 int s=1;
// 	 return Path_nodes;

// }


// void publisher(vector<Point> Path)
// {
	
// 	RRT a_1;
// 	ros::NodeHandle v;
// 		  	ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1);
		  	
// 		  	nav_msgs::Path poses;
// 		  	poses.header.frame_id = "map";
		  
// 		  	 {
// 		  	 	poses.poses.clear();
		  	
// 		  		for(int i=0; i<Path.size(); i++)
// 		  		{
// 		  			geometry_msgs::PoseStamped vertex;
// 		  			vertex.pose.position.x= Path[i].x;
// 		  			vertex.pose.position.y= Path[i].y;
// 		  			vertex.pose.position.z= 0;
		  
		  		
		  
		  		
// 		  			poses.poses.push_back(vertex);
// 		  		}
		  
// 		  		chatter_pub.publish(poses);
		  		
// 		  	 }  
// }



// void RoadCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
// {
// 	if(!msg->data.empty())
// 	{
// 		checkMap = true;

// 		int i,j;
// 		RoadMapW = msg->info.width;
// 		RoadMapH = msg->info.height;
		
// 		std::vector<int> v;
// 		for (i=0; i<RoadMapW; i++) v.push_back(0);
// 		for (i=0; i<RoadMapH; i++) obstacle_map.push_back(v);

		
// 		for(i=0;i<RoadMapH;i++)//putting values
// 		{
// 			for(j=0;j<RoadMapW;j++)
// 			{
// 				if(msg->data[i*RoadMapW+j]>=40)
// 				{
// 					obstacle_map[i][j] = int(msg->data[i*RoadMapW+j]);
// 				}
// 			}
// 		}

		


// 		int m=1;

// 		for(i=0;i<RoadMapH;i++)//putting values
// 		{
// 			for(j=0;j<RoadMapW;j++)
// 			{
// 				if(i!=0 and j!=0 and i!= RoadMapH-1 and j!= RoadMapW-1)
// 				{	
// 					if(obstacle_map[i][j]>= 70)
// 					{
// 						for(int k=1; k<=m; k++)
// 						{
// 							for(int p=1; p<=m; p++)
// 							{
// 								obstacle_map[i][j+p]= 60;
// 								obstacle_map[i-k][j+p]= 60;
// 								obstacle_map[i+k][j+p]= 60;
// 								obstacle_map[i+k][j]= 60;
// 								obstacle_map[i-k][j]= 60;
// 								obstacle_map[i-k][j-p]= 60;
// 								obstacle_map[i][j-p]= 60;
// 								obstacle_map[i+k][j-p]= 60;
// 							}
// 					}
// 				}
// 			}
// 		}


		
// 		int h = 0;


// 		for(int i = 0; i<RoadMapH; i++)
// 		{
// 			for(int j= 0; j<RoadMapW;j++)
// 			{
// 				h++;
// 				if(obstacle_map[i][j]>50)
// 					cout<<1;
// 				else
// 					cout<<obstacle_map[i][j];
// 			}
// 			cout<<endl;
// 		}
// 		cout<<RoadMapH<< " "<<RoadMapW;
		
// 		vector<Point> Path;

		
		
  
// 	if(checkMap == true )
// 		{

// 		  	vector<Node*> Path_nodes= find_path();
		  	
// 		  	for(int i=0; i< Path_nodes.size(); i++)
// 		  	{
// 		  		Path.push_back(Path_nodes[i]->P);
// 		  	}
// 		}

		 


// 		publisher(Path);
	

// 	}
// }
// }

// int main(int argc, char **argv)
// {
	
// 	RRT a_1;

// 	ros::init(argc, argv, "rrt");

// 	ros::NodeHandle LRSubNode, MapPubNode;
// 	ros::Subscriber SubRoad = LRSubNode.subscribe<nav_msgs::OccupancyGrid>("occ_map", 1, RoadCallback);

// 	chatter_pub = MapPubNode.advertise<nav_msgs::Path>("PATH", 1);;

	
 		  	 
// 				ros::Rate loop_rate(10);
// 				ros::spin();
		  
// 				loop_rate.sleep();

// 	return 0;
// }














































































// #include<iostream>
// #include<vector>
// #include<stdlib.h>
// #include<time.h>
// #include<math.h>
// #include "ros/ros.h"
//  #include "std_msgs/Header.h"
// #include "geometry_msgs/Pose.h"
// #include "nav_msgs/MapMetaData.h"
// #include "nav_msgs/OccupancyGrid.h"
// #include "nav_msgs/Path.h"
// // #include <typeinfo>
// using namespace std;

// bool checkMap = false;
// float stepsize= 3;
// float radius= 10;
// float goal_radius= 4;
// int RoadMapW, RoadMapH;

// float arr[2][4]= {{20, 60, 20, 50}, {50, 80, 50, 80}};
// int s= sizeof(arr)/sizeof(arr[0]);


// struct Point
// {
// 	double x;
// 	double y;
// };

// struct Node
// {

// 	float cost;
// 	Point P; 
// 	Node *parent;

// };

// int goalx = 35;
// int goaly = 35;
// int begx = 20;
// int begy = 0;


// Point gridSize = {RoadMapW, RoadMapH};

// Point goal= {goalx, goaly};
// Point beg= {begx, begy};

// //int arr_1[gridx][gridy];
// vector<vector<int> > obstacle_map;


// //ros::init("rrt");
// ros::Publisher chatter_pub;
// nav_msgs::Path poses;


// /*for(int i=0; i<abs(goal.x-beg.x+1); i++)
// 	for(int j=0; j<abs(goal.y-beg.y+1))
// 		arr_1[i][j]= 0;
// for(int i=0; i<s; i++)
// {
// 	for(int j=arr[i][0]; j<=arr[i][1]; j++)
// 		for(int k=arr[i][2]; k<=arr[i][3]; j++)
// 			arr_1[i][j]= 1;
// }*/



// // Point x_centre= {(goal.x+beg.x)/2, (goal.y+beg.y)/2};


// // float c_min= sqrt((goal.x-beg.x)*(goal.x-beg.x) + (goal.y-beg.y)*(goal.y-beg.y));
// // float C[2][2]= {{(goal.x-beg.x)/c_min, (goal.x-beg.x)/c_min}, {(goal.y-beg.y)/c_min, (goal.y-beg.y)/c_min}} ;


// class RRT
// {
// public:
// 	Node* start = new Node;
// 	// start = &dd;
// 	vector<Node*> all_nodes;
// 	Node* final = new Node;
// 	Node sstart;
// 	RRT()
// 	{
		
		
// 		//cout<<"aa "<<(*start).P.x<<endl;
// 		//cout<<start->P.x<<endl;
		
// 		//cout<<sstart.P.x<<endl;
// 		(*start).P.x = beg.x;
		
// 		(*start).P.y = beg.y;
		
// 		start->parent= NULL;
		
// 		start->cost= 0;
		
// 		all_nodes.push_back(start);
		
// 		final->parent= NULL;
		
// 	}
// 	Node* generate_randnode()
// 	{

// 		// rand();
// 		// int asdfghjkhgfdsa = 1;
// 		Point gridSize = {RoadMapW, RoadMapH};
// 		//cout<<4444444<<endl;
// 		//cout<<gridSize.x<<","<<gridSize.y<<endl;
// 		Point p= {(rand() % int(gridSize.x)) +0, ((rand() % int(gridSize.y+0)))+0};
// 		bool a= true;
// 		//cout<<5555555<<endl;
// 		/*cout<<"sssssss"<<endl;
// 		for(int i= 0; i< all_nodes.size(); i++)
// 		{
// 			//cout<<"sssssss"<<endl;
// 			if(((p.x= (all_nodes[i]->P).x) && (p.y= (all_nodes[i]->P).y)))
// 				a= false;
				
// 		}*/
// 		if(a)
// 		{
// 			Node* rand_node= new Node;
// 			rand_node-> P= p;
// 			rand_node-> parent= NULL;
// 			rand_node->cost= 0;
// 			return rand_node;
// 		}
// 		else
// 			generate_randnode();
// 	}
		


// 	/*float** multiply_matrices(float a[2][2], float b[2][2])
// 	{
// 		// float** c;
// 		float** c= new float*[2];
// 		c[0]= new float[2];
// 		c[1]= new float[2];
// 		c[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
// 		c[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];
// 		c[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
// 		c[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
// 		return c;
// 	}
// 	float* multiply_matr_vec(float a[2][2], float b[2])
// 	{
// 		float c_1[2];
// 		c_1[0]= a[0][0]*b[0] + a[0][1]*b[1];
// 		c_1[1]= a[1][0]*b[0] + a[1][1]*b[1];
// 		return c_1;
// 	}
// 	Node* sample(float c_best)
// 	{
// 		float r= (float) rand()/RAND_MAX;
// 		float theta= (float) rand()/RAND_MAX* 2*22/7;
// 		float s_1[2];
// 		s_1[0]= r*cos(theta);
// 		s_1[1]= r*sin(theta);
// 		float L[2][2]= {{0,0}, {0,0}};
// 		L[0][0]= c_best/2;
// 		L[1][1]= 0.5*sqrt(c_best*c_best - c_min*c_min);
// 		float** k=multiply_matrices(C, L);
		
// 		float* p= multiply_matr_vec(&&k, s_1);
// 		Point n;
// 		n.x= p[0]+x_centre.x;
// 		n.y= p[1]+x_centre.y;
// 		Node* rand_1;
// 		rand_1->P= n;
// 		if((obstacle_check(rand_1)) && n.x<= gridSize.x && n.y<= gridSize.y)
// 		{
// 			rand_1->parent= NULL;
// 			return rand_1;
// 		}
// 		else
// 			sample(c_best);
// 	}*/

// 	vector<Node*> near_nodes(Node* N)
// 	{
// 		//cout<<12345<<endl;
// 		vector<Node*> nearby_nodes;
// 		int e=1;
// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			if(distance(all_nodes[i]->P, N->P)< radius)
// 			{
// 				// cout<<"boom "<<all_nodes[i]->P.x<<" "<<all_nodes[i]->P.y<<endl;
// 				nearby_nodes.push_back(all_nodes[i]);
// 			}
// 			if(all_nodes[i]==N)
// 			{
// 				//cout<<i;
// 				e=i;
// 			}
// 		}
// 		//cout<<endl<<3<<endl;
// 		//nearby_nodes.erase(nearby_nodes.begin()+ e);
// 		//cout<<nearby_nodes.size()<<endl<<"11236432875260746597284343798247897432894890952"<<endl;
// 		return nearby_nodes;
// 	}



// 	// bool obstacle_check_1(Node* N)
// 	// {
// 	// 	Point p= N->P;
// 	// 	int a, b;
// 	// 	a= p.x;
// 	// 	b= p.y;
// 	// 	int bb = 1, aa = 1;
// 	// 	if(b>99)
// 	// 	{
// 	// 		b = 99;
// 	// 	}
// 	// 	for(int i=0; i<s; i++)
// 	// 	{
// 	// 		if((p.x>=(arr[i][0]-0)&&p.x<=(arr[i][1]+0)) && (p.y>=(arr[i][2]-0)&&p.y<=(arr[i][3]+0)))
// 	// 		{
// 	// 			bb = 0;
// 	// 			// return false;
// 	// 		}
// 	// 	}
// 	// 	if(arr_1[a][b]==1)
// 	// 	{
// 	// 		aa = 0;
// 	// 	}
// 	// 	if(aa!=bb)
// 	// 	{

// 	// 		cout<<"booooooom "<<aa<<bb<<endl;
// 	// 	}
// 	// 	if(!(a<100 and a>=0 && b>=0 && b<100))
// 	// 	{
// 	// 		cout<<"asdfghj "<<a<<" "<<b<<"\n";
// 	// 	}
// 	// 	return bb;
// 	// }

// 	// bool obstacle_check_2(Node* N)
// 	// {
// 	// 	Point p= N->P;
// 	// 	for(int i=0; i<s; i++)
// 	// 	{
// 	// 		if((p.x>=(arr[i][0]-1)&&p.x<=(arr[i][1]+1)) && (p.y>=(arr[i][2]-1)&&p.y<=(arr[i][3]+1)))
// 	// 			return false;
// 	// 	}
// 	// 	return true;
// 	// }

// 	bool obstacle_check(Node* N)
// 	{
// 		Point p= N->P;
// 		int a, b;
// 		a= p.x;
// 		b= p.y;
// 		if(obstacle_map[a][b]==1)
// 			return false;
// 		return true;
// 	}


// 	bool linejoin_check(Node* a, Node*b)
// 	{
// 		Point A= a->P;
// 		Point B= b->P;
// 		Node* N_1= new Node;
// 		Node* N_2= new Node;
// 		Node* N_3= new Node;
// 		Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
// 		Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
// 		Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
// 		N_1->P= n_1;
// 		N_2->P= n_2;
// 		N_3->P= n_3;
// 		if(!(obstacle_check(N_1)))
// 			return 0;
// 		else if(!(obstacle_check(N_2)))
// 			return 0;
// 		else if(!(obstacle_check(N_3)))
// 			return 0;
// 		else
// 			return 1;
// 	}


// 	Node* nearest_node(Node* N)
// 	{
// 		Node* nearest= new Node;
// 		float d= 1000000;
// 		float m;
// 		//vector<Node*> all_= near_nodes(N);

// 		for(int i=0; i< all_nodes.size(); i++)
// 		{
// 			m= distance(all_nodes[i]->P, N->P);
// 			if(m<d)
// 			{
// 				d= m;
// 				nearest= all_nodes[i];
// 			}	
// 		}
// 		return nearest;
// 	}


// 	Node* new_node(Node* nearest, Node* N)
// 	{
// 		Node* new_node= new Node;
// 		float s= stepsize;
// 		Point m;
// 		//cout<<distance(nearest->P, N->P)<<endl;
// 		if(linejoin_check(nearest, N))
// 		{
// 			if((distance(N->P, nearest->P)< s))
// 			{
// 				new_node->P= N->P;
// 				new_node->cost= nearest->cost+ distance(N->P, nearest->P);
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 			else
// 			{
// 				m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
// 				m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
// 				new_node->P= m;
// 				new_node->cost= nearest->cost + s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 		}
// 		//cout<<nearest->P.x<<endl<<nearest->P.y<<endl;
// 		//cout<<"00000000000000"<<endl<<m.x<<endl<<m.y<<endl;
// 		int a= 1;
			



// 		/*while(a && s> 0.01*stepsize)
// 		{
// 			if(!obstacle_check(new_node))
// 			{
				
// 				(new_node->P).x= 0.9*(new_node->P).x+ 0.1*(nearest->P).x;
// 				(new_node->P).y= 0.9*(new_node->P).y+ 0.1*(nearest->P).y;
// 				s*= 0.9;   
// 				//cout<<new_node->P.x<<endl<<new_node->P.y<<endl<<endl;
// 			}
// 			else
// 			{
// 				a= 0;
// 				new_node->cost= nearest->cost+ s;
// 				new_node->parent= nearest;
// 				all_nodes.push_back(new_node);
// 				return new_node;
// 			}
// 		}*/






// 		/*if(a==0)
// 		{
// 			new_node->cost= nearest->cost+ s;
// 			new_node->parent= nearest;
// 			all_nodes.push_back(new_node);
// 			return new_node;
// 		}*/

// 			//cout<<a<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
// 			return NULL;
		
// 	}


// 	float distance(Point a, Point b)
// 	{
// 		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
// 	}




// 	Node* best_parent(Node* N)
// 	{
// 		vector<Node*> q= near_nodes(N);
// 		//cout<<"6666666666"<<q.size()<<endl;
// 		Node* best= new Node;
// 		best->cost = 10000000;
// 		float best_cost = best->cost;
// 		float now_cost = best->cost;
// 		// cout<<"innnnnnnnnnnnnnn"<<endl;
// 		for(int i= 0; i<q.size(); i++)
// 		{
// 			//cout<<"cost"<<" "<<q[i]->cost<<endl;
// 			if(!(q[i]== N))
// 			{
// 				//cout<<"shoot "<<q[i]->cost<<endl;
// 				//+ distance(q[i]->P, N->P)
// 				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
// 				if(now_cost < best_cost)
// 				{
// 					//cout<<"in here"<<q[i]->P.x<<" "<<q[i]->P.y<<" "<<linejoin_check(q[i], N)<<endl;
					
// 					if((linejoin_check(q[i], N)))
// 					{
// 						best= q[i];
// 						// cout<<"asdfghjkl"<<endl;
// 						best_cost = now_cost;
// 						// best->cost = best_cost;
// 					}
// 				}
// 			}
// 		}
// 		// cout<<"fu"<<endl;
// 		if(!(q.size()==1))
// 		{
// 			// cout<<"in here"<<best->P.x<<" "<<best->P.y<<endl;
// 			// cout<<"8888888888888"<<endl;
// 			N->cost= best_cost;
// 			N->parent= best;
// 			return best;
// 		}
// 		else
// 		{
// 			// cout<<"1111111111111"<<endl;
// 			return N->parent;
// 		}	
// 	}

// 	void rewire(Node* N)
// 	{
// 		vector<Node*> w= near_nodes(N);


// 		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
// 			w.push_back(final);
// 		//cout<<w.size();
// 		Node* bestparent_n= best_parent(N);


// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if(bestparent_n== w[i])
// 			{
// 				w.erase(w.begin()+ i);
// 				break;
// 			}
			
// 		}


		
// 		for(int i=0; i<w.size(); i++)
// 		{
// 			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost)
// 			{
				

// 				//cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
// 				if((linejoin_check(N, w[i])))
// 				{
// 					w[i]->parent= N;
// 					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
// 				}

// 			}
// 		}

// 	}

// 	bool goal_check(Node* N, Point goal)
// 	{
// 		if(distance(N->P, goal) < goal_radius)
// 		{
// 			final->parent= N;
// 			final->P= goal;
// 			final->cost= N->cost+ distance(N->P, goal);
// 			return true;
// 		}
// 		return false;
// 	}

// 	vector<Node*> shortest_path(Node* start, Node* final)
// 	{
// 		vector<Node*> path;
		
// 		Node* a= final;
// 		int i=1;
// 			while(!(a->parent== NULL))
// 			{
// 				//cout<<i<<endl;

// 				path.push_back(a);
				
// 				//cout<<path.size()<<endl;
// 				if((a->parent==start))
// 					path.push_back(start);
// 				a= a->parent;
				
// 				i++;
				
// 			}
			
			
// 			//path.push_back(start->P);
// 		return path;
// 	}


// };



// vector<Node*> find_path()
// {
// 	//cout<<3333333333333<<endl;
// 	RRT rrt;	
// 	bool c= 0;

// 	int iter_max= 3000;
// 	vector<Node*> Path_nodes;
// 	vector<Point> random_nodes;
// 	Node* rand_n= new Node;
// 	Node* nearest_1= new Node;
// 	Node* new_n= new Node;

// 	int check= 1;


// 	for(int i= 1; i<iter_max; i++)
// 	{
		
// 		//cout<<333333333564333<<endl;

// 		rand_n= rrt.generate_randnode();
// 		//cout<<3333333333333<<endl;
// 		random_nodes.push_back(rand_n->P);
// 		nearest_1= rrt.nearest_node(rand_n);
		
// 		new_n= rrt.new_node(nearest_1, rand_n);
// 		if(!(new_n==NULL))
// 		{
			

// 			c= !(rrt.final->parent== NULL);
// 			//cout<<c<<endl;

// 			if(c==1)
// 			{
				
// 				rrt.best_parent(new_n);
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
				
// 				}
// 				Path_nodes= rrt.shortest_path(rrt.start, rrt.final);
				
// 			}
// 			else
// 			{
// 				rrt.best_parent(new_n);				
// 				rrt.rewire(new_n);
// 				if(check==1)
// 				{
// 					if(rrt.goal_check(new_n, goal))
// 					{
// 						check=0;
// 					}
// 				}
// 			}
// 		}


		

// 	}
// 	float q= 0;

// 	vector<Point> Path;

// 	for(int i=0; i< Path_nodes.size(); i++)
// 	{
// 		Path.push_back(Path_nodes[i]->P);
// 	}

// 	 //for(int i=0;i<Path.size();i++)
// 	 //{
// 	 	//cout<<Path[i].x<< ", "<< Path[i].y<< endl;

// 	 //}

// 	// cout<<5555555<<endl;

// 	// vector<Node*> all_1= rrt.all_nodes;
	 
// 	//  cout<<rrt.linejoin_check(rrt.start, rrt.final)<<endl<<666<<endl;;

	 

// 	 // for(int i=0;i<Path.size();i++)
// 	 // {
// 	 // 	cout<<Path[i].x<< ", "<< Path[i].y<< endl<<Path_nodes[i]->cost<<endl;
// 	 // 	if(i>0)
// 	 // 		cout<<rrt.distance(Path[i], Path[i-1])<<endl<<endl;

// 	 // }

// 	  cout<<endl<<rrt.final->cost<<endl;
	 
	 
	 
	 
// 	 int s=1;
// 	 return Path_nodes;

// }


// void publisher(vector<Point> Path, ros::Publisher chatter_pub, nav_msgs::Path poses)
// {
	
// 	RRT a_1;
	
		  
// 		  	// nav_msgs::OccupancyGrid MyGrid;
		  
// 		  	// MyGrid.header.stamp = ros::Time::now();
// 		  	// MyGrid.header.frame_id = "map";
// 		  	// MyGrid.info.resolution = 1.0;
// 		  	// MyGrid.info.origin.position.x = 0.0;
// 		  	// MyGrid.info.origin.position.y = 0.0;
// 		  	// MyGrid.info.origin.position.z = 0.0;
// 		  	// MyGrid.info.origin.orientation.x = 0.0;
// 		  	// MyGrid.info.origin.orientation.y = 0.0;
// 		  	// MyGrid.info.origin.orientation.z = 0.0;
// 		  	// MyGrid.info.origin.orientation.w = 0.0;
// 		  	// MyGrid.info.width = RoadMapW;
// 		  	// MyGrid.info.height = RoadMapH;
// 		  	// MyGrid.info.map_load_time = ros::Time::now();
		  


// 		  	// bool b= true;
// 		  	// // int xcvb = 0;
// 		  	// for(int i=0;i<RoadMapW;i++)
// 		  	// {
// 		  	// 	for(int j=0;j<RoadMapH;j++)
// 		  	// 	{

// 		  	// 		Node* e = new Node;
// 		  	// 		//cout<<"$$$$"<<endl;
// 		  	// 		Point abc = {i, j};
// 		  	// 		e->P.x= i;
// 		  	// 		e->P.y= j;
// 		  	// 		//cout<<99999<<endl;
		  
// 		  	// 			if(!a_1.obstacle_check(e))
// 		  	// 			{
// 		  	// 				// xcvb++;
// 		  	// 				MyGrid.data.push_back(100);
// 		  	// 				break;
// 		  	// 			}
		  			
// 		  	// 		if(b)
// 		  	// 		{
// 		  	// 			// xcvb++;
// 		  	// 			MyGrid.data.push_back(0);
// 		  	// 		}
// 		  	// 	}
// 		  	// }



// 		  	// cout<<xcvb<<" asd"<<endl;
// 		  	 // while (ros::ok())
// 		  	 {
// 		  	 	poses.poses.clear();
// 		  		// cout<<count<<endl;
		  
// 		  		for(int i=0; i<Path.size(); i++)
// 		  		{
// 		  			geometry_msgs::PoseStamped vertex;
// 		  			vertex.pose.position.x= Path[i].x;
// 		  			vertex.pose.position.y= Path[i].y;
// 		  			vertex.pose.position.z= 0;
		  
		  		
		  
		  		
// 		  			poses.poses.push_back(vertex);
// 		  		}
		  
// 		  		chatter_pub.publish(poses);
// 		  		//map_pub.publish(MyGrid);
		  
		  
// 		      	//count++;
		  		
// 		  	 }  
// }



// void RoadCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
// {
// 	//cout<<666666<<endl;
// 	if(!msg->data.empty())
// 	{
// 		checkMap = true;

// 		int i,j;
// 		RoadMapW = msg->info.width;
// 		RoadMapH = msg->info.height;
// 		begx = RoadMapW/2;
// 		begy = 0;
// 		goalx = 20;
// 		goaly = 20;

// 		std::vector<int> v;
// 		for (i=0; i<RoadMapW; i++) v.push_back(0);
// 		for (i=0; i<RoadMapH; i++) obstacle_map.push_back(v);

// 			//cout << "2\n";

// 		for(i=RoadMapH-1;i>=0;i--)//putting values
// 		{
// 			for(j=0;j<RoadMapW;j++)
// 			{
// 				// int i1;
// 				// i1=RoadMapH-1-i;
// 				if(msg->data[i*RoadMapW+j]==2)
// 				{
// 					obstacle_map[j][i] = msg->data[i*RoadMapW+j];
// 				}
// 			}
// 		}

// 		vector<Point> Path;
//  	//cout<<"###"<<checkMap<<endl;

  
// 	if(checkMap == true )
// 		{

// 		  	//cout<<2222;
// 		  	vector<Node*> Path_nodes= find_path();
// 		  	//cout<<"%%%%%%%%%%%%%%%%%"<<endl;
// 		  	//cout<<555<<endl<<Path_nodes.size()<<endl;
		  	
// 		  	for(int i=0; i< Path_nodes.size(); i++)
// 		  	{
// 		  		Path.push_back(Path_nodes[i]->P);
// 		  	}
// 		}

		 


// 		  publisher(Path, chatter_pub, poses);
	

// 		//cout<<RoadMapW<<","<<RoadMapH<<endl<<endl;
// 		//cout << "3\n";
// 	}
// }






// int main(int argc, char **argv)
// {
// 	/*for(int i=0; i<=gridx; i++)
// 		for(int j=0; j<=gridy;j++)
// 			arr_1[i][j]= 0;
// 	for(int i=0; i<s; i++)
// 	{
// 		for(int j=arr[i][0]-1; j<arr[i][1]+1; j++)
// 		{
// 			for(int k=arr[i][2]-1; k<arr[i][3]+1; k++)
// 			{
// 				if(j>=0 and j<100 and k>=0 and k<100)
// 					arr_1[j][k]= 1;
// 			}
// 		}
// 	}*/

// 	RRT a_1;

// 	//cout<<checkMap<<endl;
// 	ros::init(argc, argv, "rrt");

// 	ros::NodeHandle LRSubNode;
// 	ros::Subscriber SubRoad = LRSubNode.subscribe<nav_msgs::OccupancyGrid>("occ_map", 1, RoadCallback);

	
//  //  	vector<Point> Path;
//  // 	//cout<<"###"<<checkMap<<endl;
  
// 	// if(checkMap == true )
// 	// 	{
// 	// 	  	//cout<<2222;
// 	// 	  	vector<Node*> Path_nodes= find_path();
// 	// 	  	//cout<<555<<endl<<Path_nodes.size()<<endl;
		  	
// 	// 	  	for(int i=0; i< Path_nodes.size(); i++)
// 	// 	  	{
// 	// 	  		Path.push_back(Path_nodes[i]->P);
// 	// 	  	}
// 	// 	  }
// 	// 	  		int count= 0;
		  
		  	 
// 		ros::NodeHandle v;
// 		  	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 		  	 chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1);
// 		  	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1);
// 		  	 poses.header.frame_id = "map";
		  
		  	

		  
// 	 	  	 //ros::NodeHandle v;
// 	// 	  	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
// 	// 	  	 ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1);
// 	// 	  	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1);
		  
// 	// 	  	nav_msgs::Path poses;
// 	// 	  	poses.header.frame_id = "map";
		  
// 	// 	  	nav_msgs::OccupancyGrid MyGrid;
		  
// 	// 	  	MyGrid.header.stamp = ros::Time::now();
// 	// 	  	MyGrid.header.frame_id = "map";
// 	// 	  	MyGrid.info.resolution = 1.0;
// 	// 	  	MyGrid.info.origin.position.x = 0.0;
// 	// 	  	MyGrid.info.origin.position.y = 0.0;
// 	// 	  	MyGrid.info.origin.position.z = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.x = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.y = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.z = 0.0;
// 	// 	  	MyGrid.info.origin.orientation.w = 0.0;
// 	// 	  	MyGrid.info.width = RoadMapW;
// 	// 	  	MyGrid.info.height = RoadMapH;
// 	// 	  	MyGrid.info.map_load_time = ros::Time::now();
		  
// 	// 	  	bool b= true;
// 	// 	  	// int xcvb = 0;
// 	// 	  	for(int i=0;i<RoadMapW;i++)
// 	// 	  	{
// 	// 	  		for(int j=0;j<RoadMapH;j++)
// 	// 	  		{
// 	// 	  			Node* e;
// 	// 	  			e->P.x= i;
// 	// 	  			e->P.y= j;
		  
// 	// 	  				if(!a_1.obstacle_check(e))
// 	// 	  				{
// 	// 	  					// xcvb++;
// 	// 	  					MyGrid.data.push_back(100);
// 	// 	  					break;
// 	// 	  				}
		  			
// 	// 	  			if(b)
// 	// 	  			{
// 	// 	  				// xcvb++;
// 	// 	  				MyGrid.data.push_back(0);
// 	// 	  			}
// 	// 	  		}
// 	// 	  	}
// 	// 	  	// cout<<xcvb<<" asd"<<endl;
// 	// 	  	 // while (ros::ok())
// 	// 	  	 {
// 	// 	  	 	poses.poses.clear();
// 	// 	  		 cout<<count<<endl;
		  
// 	// 	  		for(int i=0; i<Path.size(); i++)
// 	// 	  		{
// 	// 	  			geometry_msgs::PoseStamped vertex;
// 	// 	  			vertex.pose.position.x= Path[i].x;
// 	// 	  			vertex.pose.position.y= Path[i].y;
// 	// 	  			vertex.pose.position.z= 0;
		  
		  		
		  
		  		
// 	// 	  			poses.poses.push_back(vertex);
// 	// 	  		}
		  
// 	// 	  		chatter_pub.publish(poses);
// 	// 	  		map_pub.publish(MyGrid);
		  
		  
// 	// 	      	count++;
		  		
// 	// 	  	 }  
		  	 
// 				ros::Rate loop_rate(10);
// 				ros::spin();
		  
// 				loop_rate.sleep();

// 	return 0;
// }

















































































#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include "ros/ros.h"
 #include "std_msgs/Header.h"
#include "geometry_msgs/Pose.h"
#include "nav_msgs/MapMetaData.h"
#include "nav_msgs/OccupancyGrid.h"
#include "nav_msgs/Path.h"
// #include <typeinfo>
using namespace std;


int no_of_times = 0;

bool checkMap = false;
float stepsize= 3;
float radius= 10;
float goal_radius= 4;
int RoadMapW, RoadMapH;


//float arr[2][4]= {{20, 60, 20, 50}, {50, 80, 50, 80}};
float arr[2][4]= {{50, 70, 10, 90}};
int s= sizeof(arr)/sizeof(arr[0]);


struct Point
{
	double x;
	double y;
};

struct Node
{

	float cost;
	Point P; 
	Node *parent;

};

int goalx = 80;
int goaly = 70;
int begx = 20;
int begy = 0;

const int arr_size = 1000;

const int gridx = 100;
const int gridy = 100;

Point gridSize = {gridx, gridy};

Point goal= {goalx, goaly};
Point beg= {begx, begy};

// int arr_1[arr_size][arr_size];
int arr_1[1000][1000];


vector<vector<int> > obstacle_map;


//ros::init("rrt");
ros::Publisher chatter_pub;
nav_msgs::Path poses;

/*for(int i=0; i<abs(goal.x-beg.x+1); i++)
	for(int j=0; j<abs(goal.y-beg.y+1))
		arr_1[i][j]= 0;
for(int i=0; i<s; i++)
{
	for(int j=arr[i][0]; j<=arr[i][1]; j++)
		for(int k=arr[i][2]; k<=arr[i][3]; j++)
			arr_1[i][j]= 1;
}*/



// Point x_centre= {(goal.x+beg.x)/2, (goal.y+beg.y)/2};


// float c_min= sqrt((goal.x-beg.x)*(goal.x-beg.x) + (goal.y-beg.y)*(goal.y-beg.y));
// float C[2][2]= {{(goal.x-beg.x)/c_min, (goal.x-beg.x)/c_min}, {(goal.y-beg.y)/c_min, (goal.y-beg.y)/c_min}} ;


class RRT
{
public:
	Node* start = new Node;
	// start = &dd;
	vector<Node*> all_nodes;
	Node* final = new Node;
	Node sstart;
	RRT()
	{
		
		
		//cout<<"aa "<<(*start).P.x<<endl;
		//cout<<start->P.x<<endl;
		
		//cout<<sstart.P.x<<endl;
		(*start).P.x = beg.x;
		
		(*start).P.y = beg.y;
		
		start->parent= NULL;
		
		start->cost= 0;
		
		all_nodes.push_back(start);
		
		final->parent= NULL;
		
	}
	Node* generate_randnode()
	{
		// rand();
		// int asdfghjkhgfdsa = 1;
		Point p= {(rand() % int(RoadMapW+0)) +0, ((rand() % int(RoadMapH+0)))+0};
		bool a= true;
		/*cout<<"sssssss"<<endl;
		for(int i= 0; i< all_nodes.size(); i++)
		{
			//cout<<"sssssss"<<endl;
			if(((p.x= (all_nodes[i]->P).x) && (p.y= (all_nodes[i]->P).y)))
				a= false;
				
		}*/

		Node* m = new Node;
		m->P = p;

		if(obstacle_check(m))
		{
			Node* rand_node= new Node;
			rand_node-> P= p;
			rand_node-> parent= NULL;
			rand_node->cost= 0;
			return rand_node;
		}
		else
			generate_randnode();
	}
		


	/*float** multiply_matrices(float a[2][2], float b[2][2])
	{
		// float** c;
		float** c= new float*[2];
		c[0]= new float[2];
		c[1]= new float[2];
		c[0][0]= a[0][0]*b[0][0] + a[0][1]*b[1][0];
		c[0][1]= a[0][0]*b[0][1] + a[0][1]*b[1][1];
		c[1][0]= a[1][0]*b[0][0] + a[1][1]*b[1][0];
		c[1][1]= a[1][0]*b[0][1] + a[1][1]*b[1][1];
		return c;
	}
	float* multiply_matr_vec(float a[2][2], float b[2])
	{
		float c_1[2];
		c_1[0]= a[0][0]*b[0] + a[0][1]*b[1];
		c_1[1]= a[1][0]*b[0] + a[1][1]*b[1];
		return c_1;
	}
	Node* sample(float c_best)
	{
		float r= (float) rand()/RAND_MAX;
		float theta= (float) rand()/RAND_MAX* 2*22/7;
		float s_1[2];
		s_1[0]= r*cos(theta);
		s_1[1]= r*sin(theta);
		float L[2][2]= {{0,0}, {0,0}};
		L[0][0]= c_best/2;
		L[1][1]= 0.5*sqrt(c_best*c_best - c_min*c_min);
		float** k=multiply_matrices(C, L);
		
		float* p= multiply_matr_vec(&&k, s_1);
		Point n;
		n.x= p[0]+x_centre.x;
		n.y= p[1]+x_centre.y;
		Node* rand_1;
		rand_1->P= n;
		if((obstacle_check(rand_1)) && n.x<= gridSize.x && n.y<= gridSize.y)
		{
			rand_1->parent= NULL;
			return rand_1;
		}
		else
			sample(c_best);
	}*/

	vector<Node*> near_nodes(Node* N)
	{
		//cout<<12345<<endl;
		vector<Node*> nearby_nodes;
		int e=1;
		for(int i=0; i< all_nodes.size(); i++)
		{
			if(distance(all_nodes[i]->P, N->P)< radius)
			{
				// cout<<"boom "<<all_nodes[i]->P.x<<" "<<all_nodes[i]->P.y<<endl;
				nearby_nodes.push_back(all_nodes[i]);
			}
			if(all_nodes[i]==N)
			{
				//cout<<i;
				e=i;
			}
		}
		//cout<<endl<<3<<endl;
		//nearby_nodes.erase(nearby_nodes.begin()+ e);
		//cout<<nearby_nodes.size()<<endl<<"11236432875260746597284343798247897432894890952"<<endl;
		return nearby_nodes;
	}



	// bool obstacle_check_1(Node* N)
	// {
	// 	Point p= N->P;
	// 	int a, b;
	// 	a= p.x;
	// 	b= p.y;
	// 	int bb = 1, aa = 1;
	// 	if(b>99)
	// 	{
	// 		b = 99;
	// 	}
	// 	for(int i=0; i<s; i++)
	// 	{
	// 		if((p.x>=(arr[i][0]-0)&&p.x<=(arr[i][1]+0)) && (p.y>=(arr[i][2]-0)&&p.y<=(arr[i][3]+0)))
	// 		{
	// 			bb = 0;
	// 			// return false;
	// 		}
	// 	}
	// 	if(arr_1[a][b]==1)
	// 	{
	// 		aa = 0;
	// 	}
	// 	if(aa!=bb)
	// 	{

	// 		cout<<"booooooom "<<aa<<bb<<endl;
	// 	}
	// 	if(!(a<100 and a>=0 && b>=0 && b<100))
	// 	{
	// 		cout<<"asdfghj "<<a<<" "<<b<<"\n";
	// 	}
	// 	return bb;
	// }

	// bool obstacle_check_2(Node* N)
	// {
	// 	Point p= N->P;
	// 	for(int i=0; i<s; i++)
	// 	{
	// 		if((p.x>=(arr[i][0]-1)&&p.x<=(arr[i][1]+1)) && (p.y>=(arr[i][2]-1)&&p.y<=(arr[i][3]+1)))
	// 			return false;
	// 	}
	// 	return true;
	// }

	bool obstacle_check_1(Node* N)
	{
		Point p= N->P;
		double a, b;
		a= p.x;
		b= p.y;

		int c, d;

		if(a-floor(a) < 0.5)
			c = floor(a);
		else
			c = ceil(a);

		if(b-floor(b) < 0.5)
			d = floor(b);
		else
			d = ceil(b);

		if(arr_1[c][d]==1)
			return false;
		return true;
	}

	bool obstacle_check(Node* N)
	{
		Point p= N->P;
		int a, b;
		a= p.x;
		b= p.y;

		
		if(arr_1[a][b]==1)
			return false;
		return true;
	}


	bool linejoin_check(Node* a, Node*b)
	{
		// Point A= a->P;
		// Point B= b->P;
		// Node* N_1= new Node;
		// Node* N_2= new Node;
		// Node* N_3= new Node;
		// Point n_1= {0.5*(A.x+B.x), 0.5*(A.y+B.y)};
		// Point n_2= {0.5*(A.x+n_1.x), 0.5*(A.y+n_1.y)};
		// Point n_3= {0.5*(B.x+n_1.x), 0.5*(B.y+n_1.y)};
		// N_1->P= n_1;
		// N_2->P= n_2;
		// N_3->P= n_3;
		// if(!(obstacle_check(N_1)))
		// 	return 0;
		// else if(!(obstacle_check(N_2)))
		// 	return 0;
		// else if(!(obstacle_check(N_3)))
		// 	return 0;
		// else
		// 	return 1;


		Point A= a->P;
		Point B= b->P;
		int l = 15;
		for (int i=1;i<l;i++)
		{
			Node* N_1= new Node;
			float c_z = (float)(i)/l;
			Point n_1= {((c_z)*A.x+(1-c_z)*B.x),((c_z)*A.y+(1-c_z)*B.y)};
			N_1->P= n_1;
			if(!(obstacle_check(N_1)))
				return false;
		}
		return true;
	}


	Node* nearest_node(Node* N)
	{
		Node* nearest= new Node;
		float d= 1000000;
		float m;
		//vector<Node*> all_= near_nodes(N);

		for(int i=0; i< all_nodes.size(); i++)
		{
			m= distance(all_nodes[i]->P, N->P);
			if(m<d)
			{
				d= m;
				nearest= all_nodes[i];
			}	
		}
		return nearest;
	}


	Node* new_node(Node* nearest, Node* N)
	{
		Node* new_node= new Node;
		float s= stepsize;
		Point m;
		//cout<<distance(nearest->P, N->P)<<endl;
		// if(linejoin_check(nearest, N))
		// {
		// 	if((distance(N->P, nearest->P)< s))
		// 	{
		// 		new_node->P= N->P;
		// 		new_node->cost= nearest->cost+ distance(N->P, nearest->P);
		// 		new_node->parent= nearest;


		// 		all_nodes.push_back(new_node);
		// 		return new_node;
		// 	}
		// 	else
		// 	{
		// 		m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
		// 		m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
		// 		new_node->P= m;
		// 		new_node->cost= nearest->cost + s;
		// 		new_node->parent= nearest;


		// 		all_nodes.push_back(new_node);
		// 		return new_node;
		// 	}
		// }


		if((distance(N->P, nearest->P)< s))
		{
			if(linejoin_check(nearest, new_node))
			{
				new_node->P= N->P;
				new_node->cost= nearest->cost+ distance(N->P, nearest->P);
				new_node->parent= nearest;


				all_nodes.push_back(new_node);
				return new_node;
			}
		}
		else
		{
			m.x= 1/(distance(N->P, nearest->P))*(s*((N->P).x) + (distance(N->P, nearest->P) - s)*((nearest->P).x));
			m.y= 1/(distance(N->P, nearest->P))*(s*((N->P).y) + (distance(N->P, nearest->P) - s)*((nearest->P).y));
			new_node->P= m;
			if(linejoin_check(nearest, new_node))
			{
				new_node->cost= nearest->cost + s;
				new_node->parent= nearest;


				all_nodes.push_back(new_node);
				return new_node;
			}
		}



		//cout<<nearest->P.x<<endl<<nearest->P.y<<endl;
		//cout<<"00000000000000"<<endl<<m.x<<endl<<m.y<<endl;
		int a= 1;
			



		// while(a && s> 0.01*stepsize)
		// {
		// 	if(!obstacle_check(new_node))
		// 	{
				
		// 		(new_node->P).x= 0.9*(new_node->P).x+ 0.1*(nearest->P).x;
		// 		(new_node->P).y= 0.9*(new_node->P).y+ 0.1*(nearest->P).y;
		// 		s*= 0.9;   
		// 		//cout<<new_node->P.x<<endl<<new_node->P.y<<endl<<endl;
		// 	}
		// 	else
		// 	{
		// 		a= 0;
		// 		new_node->cost= nearest->cost+ s;
		// 		new_node->parent= nearest;

		// 		if(all_nodes.size() == 1)
		// 		{
		// 			cout << endl << endl << "$$$$$$$$$$$$$$$$$$$" << endl;
		// 			cout << new_node->P.x << " " << new_node->P.y << endl;
		// 			cout << "$$$$$$$$$$$$$" << endl;
		// 		}

		// 		all_nodes.push_back(new_node);
		// 		return new_node;
		// 	}
		// }






		/*if(a==0)
		{
			new_node->cost= nearest->cost+ s;
			new_node->parent= nearest;
			all_nodes.push_back(new_node);
			return new_node;
		}*/

			//cout<<a<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
			return NULL;
		
	}


	float distance(Point a, Point b)
	{
		return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	}




	Node* best_parent(Node* N)
	{
		vector<Node*> q= near_nodes(N);
		//cout<<"6666666666"<<q.size()<<endl;
		Node* best= new Node;
		best->cost = 10000000;
		float best_cost = best->cost;
		float now_cost = best->cost;
		// cout<<"innnnnnnnnnnnnnn"<<endl;
		for(int i= 0; i<q.size(); i++)
		{
			//cout<<"cost"<<" "<<q[i]->cost<<endl;
			if(!(q[i]== N))
			{
				//cout<<"shoot "<<q[i]->cost<<endl;
				//+ distance(q[i]->P, N->P)
				now_cost = (q[i]->cost + distance(q[i]->P, N->P));
				if(now_cost < best_cost)
				{
					//cout<<"in here"<<q[i]->P.x<<" "<<q[i]->P.y<<" "<<linejoin_check(q[i], N)<<endl;
					
					if((linejoin_check(q[i], N)))
					{
						best= q[i];
						// cout<<"asdfghjkl"<<endl;
						best_cost = now_cost;
						// best->cost = best_cost;
					}
				}
			}
		}
		// cout<<"fu"<<endl;
		if(!(q.size()==1))
		{
			// cout<<"in here"<<best->P.x<<" "<<best->P.y<<endl;
			// cout<<"8888888888888"<<endl;
			N->cost= best_cost;
			N->parent= best;
			return best;
		}
		else
		{
			// cout<<"1111111111111"<<endl;
			return N->parent;
		}	
	}

	void rewire(Node* N)
	{
		vector<Node*> w= near_nodes(N);


		if(!(final->parent== NULL) && (distance(final->P, N->P)<radius))
			w.push_back(final);
		//cout<<w.size();
		Node* bestparent_n= best_parent(N);


		for(int i=0; i<w.size(); i++)
		{
			if(bestparent_n== w[i])
			{
				w.erase(w.begin()+ i);
				break;
			}
			
		}


		
		for(int i=0; i<w.size(); i++)
		{
			if((N->cost+ distance(N->P, w[i]->P)) < w[i]->cost and w[i] != N)
			{
				if(w[i]== final)
				{
					cout<<"%%%%"<<endl<<N->cost<<endl;
					cout<<(N->cost+ distance(N->P, w[i]->P))<<endl<<w[i]->cost<<endl;
					if((linejoin_check(N, w[i])))
						cout<<222<<endl;
					if(w[i]->parent== N)
						cout<<44444444<<endl;
					cout<<N->P.x<<","<<N->P.y<<endl;
					Node* par= w[i]->parent;
					cout<<par->P.x<<","<<par->P.y<<endl;
				}


				//cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
				if((linejoin_check(N, w[i])))
				{
					w[i]->parent= N;
					w[i]->cost= N->cost+ distance(N->P, w[i]->P);
				}

				if(w[i]== final)
				{
					Node* par= w[i]->parent;
					cout<<par->P.x<<","<<par->P.y<<endl<<"%%%%%55555"<<endl;
				}

			}
		}

	}

	bool goal_check(Node* N, Point goal)
	{
		if(distance(N->P, goal) < goal_radius)
		{
			final->parent= N;
			final->P= goal;
			final->cost= N->cost+ distance(N->P, goal);
			return true;
		}
		return false;
	}

	vector<Node*> shortest_path(Node* start, Node* final)
	{
		cout << "INSIDE shortest_path " << endl;
		vector<Node*> path;
		
		Node* a= final;
		int i=1;

		cout << "vandhuruchu" << endl;
			while(!(a->parent== NULL))
			{
				cout << "i: " << i << " --> " << a->parent;

				path.push_back(a);
				
				cout<<path.size()<<endl;
				if((a->parent==start))
					path.push_back(start);
				a= a->parent;
				
				cout << "Here also -->" << endl;
				cout << a->parent << endl;
				cout << "here too" << endl;

				i++;
				
			}
			
			cout << "Here also working" << endl;
			//path.push_back(start->P);
		return path;
	}


};



vector<Node*> find_path()
{
	RRT rrt;	
	bool c= 0;
	cout << endl << "All nodes size " << rrt.all_nodes.size() << endl << endl;

	int iter_max= 4000;
	vector<Node*> Path_nodes;
	vector<Point> random_nodes;
	Node* rand_n= new Node;
	Node* nearest_1= new Node;
	Node* new_n= new Node;

	int check= 1;


	for(int i= 1; i<iter_max; i++)
	{
		cout << "i value " << i << endl;


		rand_n= rrt.generate_randnode();
		cout << "Here-->1" << endl;
		random_nodes.push_back(rand_n->P);
		cout << "Here-->2" << endl;
		nearest_1= rrt.nearest_node(rand_n);
		cout << "Here-->3" << endl;
		
		new_n= rrt.new_node(nearest_1, rand_n);
		cout << "Here-->4" << endl;
		if(!(new_n==NULL))
		{
			

			c= !(rrt.final->parent== NULL);
			//cout<<c<<endl;

			if(c==1)
			{
				
				rrt.best_parent(new_n);
				cout << "Here-->5" << endl;
				rrt.rewire(new_n);
				cout << "Here-->6" << endl;
				if(check==1)
				{
					if(rrt.goal_check(new_n, goal))
					{
						check=0;
					}
				
				}
				cout << "Here-->7" << endl;
				Path_nodes= rrt.shortest_path(rrt.start, rrt.final);
				cout << "Here-->8" << endl;
				
			}
			else
			{
				rrt.best_parent(new_n);	
				cout << "Here-->5" << endl;			
				rrt.rewire(new_n);
				cout << "Here-->6" << endl;
				if(check==1)
				{
					if(rrt.goal_check(new_n, goal))
					{
						check=0;
					}
				}
				cout << "Here-->7" << endl;
				cout << "Here-->88" << endl;
			}
		}


		

	}
	float q= 0;

	

	if(Path_nodes.size() == 0)
	{
		cout << "NOOOO PAATTHHHHHH" << endl;
		exit(0);
	}

	vector<Point> Path;

	for(int i=0; i< Path_nodes.size(); i++)
	{
		Path.push_back(Path_nodes[i]->P);
	}

	 //for(int i=0;i<Path.size();i++)
	 //{
	 	//cout<<Path[i].x<< ", "<< Path[i].y<< endl;

	 //}

	// cout<<5555555<<endl;

	// vector<Node*> all_1= rrt.all_nodes;
	 
	//  cout<<rrt.linejoin_check(rrt.start, rrt.final)<<endl<<666<<endl;;

	 cout<<rrt.all_nodes[1]->P.x<<","<<rrt.all_nodes[1]->P.y<<endl;
	 cout<<rrt.all_nodes[1]->cost<<endl<<endl;

	cout<<555555<<endl;

	 // for(int i=0;i<Path.size();i++)
	 // {
	 // 	cout<<Path[i].x<< ", "<< Path[i].y<< endl<<Path_nodes[i]->cost<<endl;
	 // 	if(i>0)
	 // 		cout<<rrt.distance(Path[i], Path[i-1])<<endl<<endl;

	 // }

	  cout<<endl<<rrt.final->cost<<endl;
	 
	 
	 
	 
	 int s=1;
	 return Path_nodes;

}






void publisher(vector<Point> Path, ros::Publisher chatter_pub, nav_msgs::Path poses)
{
	
	RRT a_1;
	
		  
		  	// nav_msgs::OccupancyGrid MyGrid;
		  
		  	// MyGrid.header.stamp = ros::Time::now();
		  	// MyGrid.header.frame_id = "map";
		  	// MyGrid.info.resolution = 1.0;
		  	// MyGrid.info.origin.position.x = 0.0;
		  	// MyGrid.info.origin.position.y = 0.0;
		  	// MyGrid.info.origin.position.z = 0.0;
		  	// MyGrid.info.origin.orientation.x = 0.0;
		  	// MyGrid.info.origin.orientation.y = 0.0;
		  	// MyGrid.info.origin.orientation.z = 0.0;
		  	// MyGrid.info.origin.orientation.w = 0.0;
		  	// MyGrid.info.width = RoadMapW;
		  	// MyGrid.info.height = RoadMapH;
		  	// MyGrid.info.map_load_time = ros::Time::now();
		  


		  	// bool b= true;
		  	// // int xcvb = 0;
		  	// for(int i=0;i<RoadMapW;i++)
		  	// {
		  	// 	for(int j=0;j<RoadMapH;j++)
		  	// 	{

		  	// 		Node* e = new Node;
		  	// 		//cout<<"$$$$"<<endl;
		  	// 		Point abc = {i, j};
		  	// 		e->P.x= i;
		  	// 		e->P.y= j;
		  	// 		//cout<<99999<<endl;
		  
		  	// 			if(!a_1.obstacle_check(e))
		  	// 			{
		  	// 				// xcvb++;
		  	// 				MyGrid.data.push_back(100);
		  	// 				break;
		  	// 			}
		  			
		  	// 		if(b)
		  	// 		{
		  	// 			// xcvb++;
		  	// 			MyGrid.data.push_back(0);
		  	// 		}
		  	// 	}
		  	// }



		  	// cout<<xcvb<<" asd"<<endl;
		  	 // while (ros::ok())
		  	 {
		  	 	poses.poses.clear();
		  		// cout<<count<<endl;
		  
		  		for(int i=0; i<Path.size(); i++)
		  		{
		  			geometry_msgs::PoseStamped vertex;
		  			vertex.pose.position.x= Path[i].x;
		  			vertex.pose.position.y= Path[i].y;
		  			vertex.pose.position.z= 0;
		  
		  		
		  
		  		
		  			poses.poses.push_back(vertex);
		  		}
		  
		  		chatter_pub.publish(poses);
		  		//map_pub.publish(MyGrid);
		  
		  
		      	//count++;
		  		
		  	 }  

		  	 ros::NodeHandle v;
		  	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1000);
		  	 nav_msgs::OccupancyGrid MyGrid;

			MyGrid.header.stamp = ros::Time::now();
			MyGrid.header.frame_id = "map";
			MyGrid.info.resolution = 1.0;
			MyGrid.info.origin.position.x = 0.0;
			MyGrid.info.origin.position.y = 0.0;
			MyGrid.info.origin.position.z = 0.0;
			MyGrid.info.origin.orientation.x = 0.0;
			MyGrid.info.origin.orientation.y = 0.0;
			MyGrid.info.origin.orientation.z = 0.0;
			MyGrid.info.origin.orientation.w = 0.0;
			MyGrid.info.width = RoadMapW;
			MyGrid.info.height = RoadMapH;
			MyGrid.info.map_load_time = ros::Time::now();

			for(int i=0;i<RoadMapH;i++)
			{
				for(int j=0;j<RoadMapW;j++)
				{
					if(arr_1[j][i] == 1)
						MyGrid.data.push_back(100);
					else
						MyGrid.data.push_back(0);	
				}
			}

			map_pub.publish(MyGrid);
}



void RoadCallback(const nav_msgs::OccupancyGrid::ConstPtr& msg)
{
	//cout<<666666<<endl;
	cout << "No of times " << no_of_times << endl;
	if(!msg->data.empty())
	{
		no_of_times++;

		cout << "INSIDE" << endl;
		for(int i=0; i<1000; i++)
			for(int j=0; j<1000;j++)
				arr_1[i][j]= 0;

		cout << "Here also" << endl;
		checkMap = true;

		int i,j;
		RoadMapW = msg->info.width;
		RoadMapH = msg->info.height;

		cout << "Road map width, height " << RoadMapH << " " << RoadMapW << endl;

		std::vector<int> v;
		for (i=0; i<RoadMapW; i++) v.push_back(0);
		for (i=0; i<RoadMapH; i++) obstacle_map.push_back(v);

			//cout << "2\n";

		cout << RoadMapW << " " << RoadMapH << endl;
		cout << endl << "#################################################################################" << endl;
		for(i=RoadMapH-1;i>=0;i--)//putting values
		{
			for(j=0;j<RoadMapW;j++)
			{
				//cout << int(msg->data[i*RoadMapW+j]);
				// int i1;
				// i1=RoadMapH-1-i;
				if(int(msg->data[i*RoadMapW+j]) > 0)
				{
					obstacle_map[j][i] = 1;
					arr_1[j][i] = 1;
				}
			}
			// cout << endl << "$$$$" << endl;
		}

		cout << endl;
		

		cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

		vector<Point> Path;
 	//cout<<"###"<<checkMap<<endl;

  
	if(checkMap == true )
		{
			cout << "inside" << endl;
		  	//cout<<2222;

			vector<Node*> Path_nodes;

		  	
		 	Path_nodes= find_path();

		  	cout << "inside_1" << endl;

		  	//cout<<"%%%%%%%%%%%%%%%%%"<<endl;
		  	//cout<<555<<endl<<Path_nodes.size()<<endl;
		  	
		  	for(int i=0; i< Path_nodes.size(); i++)
		  	{
		  		Path.push_back(Path_nodes[i]->P);
		  	}

			cout << "$$$$$$$$$$$$$$" << endl;

		  	for(int i= 0; i < Path.size(); i++)
		  		cout << Path[i].x << " " << Path[i].y << endl;

		  	cout << endl << "&&&&&&&&&&" << endl;

		  	int k = 0, sz = Path_nodes.size();

		 //  	for(int i= 0; i < RoadMapW; i++)
			// {
			// 	for(int j= 0; j < RoadMapH; j++)
			// 	{
			// 		// if(Path[k].x == j and Path[k].y == i and k < sz)
			// 		// {
			// 		// 	cout << 2;
			// 		// 	k++;
			// 		// }
			// 		// else
			// 			cout << arr_1[j][i];
			// 	}
			// 	cout << endl;
			// }
		}

		 
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;

		  publisher(Path, chatter_pub, poses);
	

		//cout<<RoadMapW<<","<<RoadMapH<<endl<<endl;
		//cout << "3\n";
	}
}






int main(int argc, char **argv)
{
	for(int i=0; i<1000; i++)
		for(int j=0; j<1000;j++)
			arr_1[i][j]= 0;
	// for(int i=0; i<s; i++)
	// {
	// 	for(int j=arr[i][0]-1; j<arr[i][1]+1; j++)
	// 	{
	// 		for(int k=arr[i][2]-1; k<arr[i][3]+1; k++)
	// 		{
	// 			if(j>=0 and j<100 and k>=0 and k<100)
	// 				arr_1[j][k]= 1;
	// 		}
	// 	}
	// }

	RRT a_1;

	//cout<<checkMap<<endl;
	ros::init(argc, argv, "rrt");

	ros::NodeHandle LRSubNode;
	ros::Subscriber SubRoad = LRSubNode.subscribe<nav_msgs::OccupancyGrid>("occ_map", 1, RoadCallback);

	
 //  	vector<Point> Path;
 // 	//cout<<"###"<<checkMap<<endl;
  
	// if(checkMap == true )
	// 	{
	// 	  	//cout<<2222;
	// 	  	vector<Node*> Path_nodes= find_path();
	// 	  	//cout<<555<<endl<<Path_nodes.size()<<endl;
		  	
	// 	  	for(int i=0; i< Path_nodes.size(); i++)
	// 	  	{
	// 	  		Path.push_back(Path_nodes[i]->P);
	// 	  	}
	// 	  }
	// 	  		int count= 0;
		  
		  	 
		ros::NodeHandle v;
		  	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
		  	 chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1);
		  	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1);
		  	 poses.header.frame_id = "map";
		  
		  	

		  
	 	  	 //ros::NodeHandle v;
	// 	  	 //ros::Publisher chatter_pub= v.advertise< nav_msgs/Path >("PATH", 1000);
	// 	  	 ros::Publisher chatter_pub = v.advertise<nav_msgs::Path>("PATH", 1);
	// 	  	 ros::Publisher map_pub = v.advertise<nav_msgs::OccupancyGrid>("MyGrid", 1);
		  
	// 	  	nav_msgs::Path poses;
	// 	  	poses.header.frame_id = "map";
		  
	// 	  	nav_msgs::OccupancyGrid MyGrid;
		  
	// 	  	MyGrid.header.stamp = ros::Time::now();
	// 	  	MyGrid.header.frame_id = "map";
	// 	  	MyGrid.info.resolution = 1.0;
	// 	  	MyGrid.info.origin.position.x = 0.0;
	// 	  	MyGrid.info.origin.position.y = 0.0;
	// 	  	MyGrid.info.origin.position.z = 0.0;
	// 	  	MyGrid.info.origin.orientation.x = 0.0;
	// 	  	MyGrid.info.origin.orientation.y = 0.0;
	// 	  	MyGrid.info.origin.orientation.z = 0.0;
	// 	  	MyGrid.info.origin.orientation.w = 0.0;
	// 	  	MyGrid.info.width = RoadMapW;
	// 	  	MyGrid.info.height = RoadMapH;
	// 	  	MyGrid.info.map_load_time = ros::Time::now();
		  
	// 	  	bool b= true;
	// 	  	// int xcvb = 0;
	// 	  	for(int i=0;i<RoadMapW;i++)
	// 	  	{
	// 	  		for(int j=0;j<RoadMapH;j++)
	// 	  		{
	// 	  			Node* e;
	// 	  			e->P.x= i;
	// 	  			e->P.y= j;
		  
	// 	  				if(!a_1.obstacle_check(e))
	// 	  				{
	// 	  					// xcvb++;
	// 	  					MyGrid.data.push_back(100);
	// 	  					break;
	// 	  				}
		  			
	// 	  			if(b)
	// 	  			{
	// 	  				// xcvb++;
	// 	  				MyGrid.data.push_back(0);
	// 	  			}
	// 	  		}
	// 	  	}
	// 	  	// cout<<xcvb<<" asd"<<endl;
	// 	  	 // while (ros::ok())
	// 	  	 {
	// 	  	 	poses.poses.clear();
	// 	  		 cout<<count<<endl;
		  
	// 	  		for(int i=0; i<Path.size(); i++)
	// 	  		{
	// 	  			geometry_msgs::PoseStamped vertex;
	// 	  			vertex.pose.position.x= Path[i].x;
	// 	  			vertex.pose.position.y= Path[i].y;
	// 	  			vertex.pose.position.z= 0;
		  
		  		
		  
		  		
	// 	  			poses.poses.push_back(vertex);
	// 	  		}
		  
	// 	  		chatter_pub.publish(poses);
	// 	  		map_pub.publish(MyGrid);
		  
		  
	// 	      	count++;
		  		
	// 	  	 }  
		  	 
				ros::Rate loop_rate(10);
				ros::spin();
		  
				loop_rate.sleep();

	return 0;
}

