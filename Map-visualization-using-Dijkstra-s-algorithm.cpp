#include<iostream>
#include<string>

using namespace std;

class graph 
{
    public:
    int city[7][7];
	int visit[7];
	string src,desti;
	
	void create_graph()                             //Function to create a graph
    {
        int i,j;
        for(i=0;i<7;i++)
        {
            for(j=0;j<7;j++)
            {
                city[i][j]=999;
            }
        }
        city[0][1]=city[1][0]=15;
        city[0][2]=city[2][0]=10;
        city[0][4]=city[4][0]=20;
        city[3][1]=city[1][3]=40;
        city[2][1]=city[1][2]=35;
        city[2][3]=city[3][2]=14;
        city[3][5]=city[5][3]=10;
        city[4][5]=city[5][4]=95;
        city[6][4]=city[4][6]=75;
        city[6][5]=city[5][6]=35;
    }
  
   int fetch_index(string str)                      //function to fetch index from name
      {
          int index=-1;
          if(str== "Punejunction")index= 0;
          else if( str=="Shivajinagar")index= 1;
          else if(str== "M.N.P")index= 2;
          else if(str== "Deccan")index= 3;
          else if( str=="Swargate")index= 4;
          else if(str== "Kothrud")index=5;
          else if (str=="Karvenagar")index=6;
       return index;
      }


      string fetch_name(int i)                      //function to fetch name from index
      {
          string str;
          switch(i)
          {
          case 0:str="Punejunction";break;
          case 1:str="Shivajinagar";break;
          case 2:str="M.N.P";break;
          case 3:str="Deccan";break;
          case 4:str="Swargate";break;
          case 5:str="Kothrud";break;
          case 6:str="Karvenagar";break;
          }
       return str;
      }

    
        int dijkstras() //dijkstra's algorithm
        {
            string source,dest;
            int s,d,i,j,min=1000,l,k=-1,m=0,cnt=0;  
            int dist[7];
            int from_vertex[7];
            int visited[7];
            string arr[7];
            cout<<"Enter Source :"<<endl;
            cin>>source;
            src=source;
            cout<<"Enter Destination :"<<endl;
            cin>>dest;
            desti=dest;
            s=fetch_index(source);
            d=fetch_index(dest);
            int v=d;
            int u=s;
            if (s!=-1 && d!=-1)
            {
                for(i=0;i<7;i++)
                    {
                        dist[i]=city[s][i];
                        from_vertex[i]=s;
                        visited[i]=0;
                    }
                visited[s]=1;
                while(s!=d)
                {
                    min=1000;
                    for(i=0;i<7;i++)
                    {
                        if(min>dist[i] && visited[i]==0)
                        {
                            min=dist[i];
                            k=i;
                            visit[i]=1;
                        }
                    }
                    s=k;
                    visited[s]=1;
                    for(j=0;j<7;j++)
                    {
                        if(visited[j]==0)
                        {
                            l=min+city[s][j];
                            if(dist[j]>l)
                            {
                                dist[j]=l;
                                from_vertex[j]=s;
                            }
                        }
                    }

                }
                for(i=0;i<7;i++)
                {
                    cout<<" "<<dist[i]<<endl;
                }

                while(v!=u)
                {
                    string nm=fetch_name(v);
                    arr[m]=nm;
                    v=from_vertex[v];
                    m++;
                    cnt++;
                }
                arr[m]=fetch_name(v);
                cout<<"Shortest path"<<endl;
                for(int z=cnt-1;z>=0;z--)
                {
                    cout<<arr[z]<<" -> ";
                }
                cout<<"\nMinimum dist: "<<dist[d]<<"km"<<endl;
                return(dist[d]);
            }
            else
            {
                cout<<"\nSorry, \nInvalid destination or source!!"<<endl;
            }
            return 0;  
        }

        void show_time(int mindistance)                         //Function to calculate time required
        {
            // Multiplying factors : bus - 7, walk - 10, bike - 5, car - 6
            cout<<"\nShortest distance from Source to Destination is "<<mindistance<<" km.\n"<<endl;
            cout<<"    Following is the Time required to go by different modes ,\n"<<endl;
            cout<<"\t Bike : "<<((mindistance*5)/60)<<" Hr "+((mindistance*5)%60)<<" min"<<endl;
            cout<<"\t Car  : "<<((mindistance*6)/60)<<" Hr "+((mindistance*6)%60)<<" min"<<endl;
            cout<<"\t Walk : "<<((mindistance*10)/60)<<" Hr "+((mindistance*10)%60)<<" min"<<endl;
            cout<<"\t Bus  : "<<((mindistance*7)/60)<<" Hr " +((mindistance*7)%60)<<" min"<<endl;          
        }

        void display()                              //display graph
        {
            cout<<"     Pune_Junction---------------SwarGate"<<endl;
            cout<<"\t|\t|\t         | \t|"<<endl;
            cout<<"\t|        |               |       |     "<<endl;
            cout<<"\t|         |              |        |"<<endl;
            cout<<"ShivajiNagar---M.N.P             |      Karvenagar"<<endl;
            cout<<"        |        |               |        |    "<<endl;
            cout<<"         |      |                |      |       "<<endl;
            cout<<"          |    |                 |     |"<<endl;
            cout<<"          Deccan----------------Kothrud  "<<endl;
        }
    
};



int main()
{
    int ch;
    int s = 0;
    graph g;
    do
    {
        cout<<("\n-----MAP VISUALIZATION-----\n1.Show Map\n2.Find Map\n3.Show Time")<<endl;
    	cout<<("Enter your choice :");
        cin>>ch;
        switch(ch)
    	{
    	    case 1: g.display();
    	            g.create_graph();
    	            break;
    	    case 2: s= g.dijkstras();
    	            break;
    	    case 3: g.show_time(s);
    	            break;
    	    default:cout<<("Exit!!!");
    	}
    }while(ch<4);
    
    return 0;
}
