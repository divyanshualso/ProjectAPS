#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph
{
private:
    map<T, list<pair<T,float>>> adjList;

public:
    list<T> path;
    // function for add the station mapping to system
    void addEdge(T u, T v, float dist, bool isBidirex=true)
    {
        adjList[u].push_back(make_pair(v,dist));
        if(isBidirex)
        {
            adjList[v].push_back(make_pair(u,dist));
        }
    }

    // function to store the all the station to list
    void DijkstraGetShortestPathTo(T destination, map<T,T> &prev)
    {
        for( ; destination != ""; destination = prev[destination])
        {
            path.push_back(destination);
        }
        path.reverse();
        cout<<"\t\t\t";
        //--
        copy(path.begin(), path.end(), ostream_iterator<T>(cout, "\n\t\t\t"));
    }

    void dijsktraSSSP(T,map<T,float> &dist, map<T,T> &prev);
    vector<string> split (const string &s, char delim)
    {
        vector<string> result;
        stringstream ss (s);
        string item;

        while (getline (ss, item, delim))
        {
            result.push_back (item);
        }

        return result;
    }

    bool check(string, string);
          
};

// function to both src and dest present in list or not
template<typename T>
bool Graph<T>::check(string src, string dest)
{
    int f=0;
    list <string> :: iterator it;
    for (it = path.begin(); it != path.end(); ++it)
    {
        if(*it==src)
        {
            f++;
        }
        else if(*it==dest)
        {
            f++;
        }
    }
    if(f==2)
        return true;
    else
        return false;
}

template<typename T>
void Graph<T>::dijsktraSSSP(T src, map<T,float> &dist, map<T,T> &prev)
{

    set<pair<float, T> > s;
    //Set all distance to infinity
    prev.clear();
    for(auto j:adjList)
    {
        dist[j.first] = numeric_limits<float>::infinity();
        prev[j.first] = "";
    }

    //Make a set to find a out node with the minimum distance

    dist[src] = 0;
    s.insert(make_pair(0,src));

    while(!s.empty())
    {

        //Find the pair at the front.
        auto p =   *(s.begin());
        T node = p.second; // NODE

        float nodeDist = p.first; //NODEDIST
        s.erase(s.begin());
        //Iterate over neighbours/children of the current node
        for(auto childPair: adjList[node])
        {
            T dest = childPair.first;
            float weight = childPair.second;
            float distance_through_node = nodeDist + childPair.second;

            if(distance_through_node < dist[childPair.first])
            {
                //In the set updation of a particular is not possible
                // we have to remove the old pair, and insert the new pair to simulation updation

                auto f = s.find( make_pair(dist[dest],dest));
                if(f!=s.end())
                {
                    s.erase(f);
                }
                //Insert the new pair
                dist[dest] = distance_through_node;
                prev[dest] = node;
                s.insert(make_pair(dist[dest],dest));
            }
        }
    }


    //Lets print distance to all other node from src
    /*for(auto d:dist)
    {
        cout<<d.first<<",is located at distance of  "<<d.second<<endl;
    }*/
}

void printAllPlaces(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening file: " << fileName << endl;
        return;
    }

    string place;
    int count = 1;
    while (getline(file, place)) {
        cout << count << ". " << place << endl;
        count++;
    }
    file.close();
}

int main()
{
    system("echo  \"\e[96m\""); // Cyan
     cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<endl;
    cout <<"                                            *********************************************" <<endl;
    cout <<"                                            *       Welcome to delhi visiting areas     *" << endl;
    cout <<"                                            *                                           *  "<<endl;
    cout <<"                                            *                                           *  "<<endl;
    cout <<"                                            *                                           *  "<<endl;
    cout <<"                                            *         Code Developed by-                *" << endl;
    cout <<"                                            *         Yash Goel                         *" << endl;
    cout <<"                                            *         Vinay Airan                       *" << endl;
    cout <<"                                            *         Ansh                              *" << endl;
    cout <<"                                            *         Ayush Raj                         *" << endl;
    cout <<"                                            *                                           *  "<<endl;
    cout <<"                                            *                                           *  "<<endl;
    cout <<"                                            *                                           *  "<<endl;
    cout <<"                                            *********************************************" << endl;
    cout <<"                                            *********************************************" << endl;

    
    string source, destination;
    Graph<string> Delhi;
 Delhi.addEdge("Red Fort (Lal Qila)","Qutub Minar",5.2);
Delhi.addEdge("Qutub Minar","India Gate",1.2);
Delhi.addEdge("India Gate","Jama Masjid",0.8);
Delhi.addEdge("Jama Masjid","Humayun's Tomb",1.2);
Delhi.addEdge("Humayun's Tomb","Lotus Temple",1.2);
Delhi.addEdge("Lotus Temple","Akshardham Temple",1.7);
Delhi.addEdge("Akshardham Temple","Chandni Chowk",0.8);
Delhi.addEdge("Chandni Chowk","National Museum",0.9);
Delhi.addEdge("National Museum","Rashtrapati Bhavan",1.1);
Delhi.addEdge("Rashtrapati Bhavan","Raj Ghat",2.2);
Delhi.addEdge("Raj Ghat","Jantar Mantar",1.6);
Delhi.addEdge("Jantar Mantar","Lodhi Gardens",1.1);
Delhi.addEdge("Lodhi Gardens","Gurudwara Bangla Sahib",2.2);
Delhi.addEdge("Gurudwara Bangla Sahib","Dilli Haat",1.6);
Delhi.addEdge("Dilli Haat","Connaught Place",1.1);
Delhi.addEdge("Connaught Place","Purana Qila",1.1);
Delhi.addEdge("Purana Qila","National Zoological Park (Delhi Zoo)",1.1);
Delhi.addEdge("National Zoological Park (Delhi Zoo)","Agrasen ki Baoli",1.1);
Delhi.addEdge("Agrasen ki Baoli","Hauz Khas Village",1.1);
Delhi.addEdge("Hauz Khas Village","Swaminarayan Akshardham",1.1);
Delhi.addEdge("Swaminarayan Akshardham","ISKCON Temple",1.1);
Delhi.addEdge("ISKCON Temple","Tughlaqabad Fort",1.1);
Delhi.addEdge("Tughlaqabad Fort","Mughal Gardens",1.1);
Delhi.addEdge("Mughal Gardens","National Rail Museum",1.1);
Delhi.addEdge("National Rail Museum","Delhi Haat INA",1.5);
Delhi.addEdge("Delhi Haat INA","Lodi Art District",1.1);
Delhi.addEdge("Lodi Art District","Nehru Planetarium",1.8);
Delhi.addEdge("Nehru Planetarium","Mughal Garden",1.9);
Delhi.addEdge("Mughal Garden","Feroz Shah Kotla Fort",2.5);
Delhi.addEdge("Feroz Shah Kotla Fort","Shri Digambar Jain Lal Mandir",1.1);
Delhi.addEdge("Shri Digambar Jain Lal Mandir","Indian War Memorial Museum",1.1);
Delhi.addEdge("Indian War Memorial Museum","National Handicrafts & Handlooms Museum",1.1);
Delhi.addEdge("National Handicrafts & Handlooms Museum","Doll Museum",3.0);
Delhi.addEdge("Doll Museum","Tibetan Market (Majnu ka Tilla)",2.2);
Delhi.addEdge("Tibetan Market (Majnu ka Tilla)","Shankar's International Dolls Museum",1.1);
Delhi.addEdge("Shankar's International Dolls Museum","Delhi Eye Ferris Wheel",1.1);
Delhi.addEdge("Delhi Eye Ferris Wheel","Sulabh International Museum of Toilets",1.1);
Delhi.addEdge("Sulabh International Museum of Toilets","Shanti Van",4.1);
Delhi.addEdge("Shanti Van","Haveli Dharampura",1.2);

    map<string,float> dist;
    map<string,string> prev;
    string sourcestn, deststn;
    int opt;
    string ch;
    
    do{
    cout<<"1: TO SHOW ALL PLACES"<<endl;
    cout<<"2: SHORTEST DISTANCE BETWEEN PLACES"<<endl;
    cin>>opt;
    cout<<endl;
    switch(opt){
        case 1:
               cout<<endl;
              printAllPlaces("places.txt");
               break;
        case 2:
     cout<<endl<<endl<<endl;
    system("echo  \"\e[32m\""); //green
    cout<<"\t\t";
     cin.ignore(); 
    cout<<"Enter source place in capital case: ";
    getline(cin,sourcestn);
    cout<<endl;

    system("echo  \"\e[33m\""); //yellow
    cout<<"\t\t";
    cout<<"Enter destination place in capital case: ";
    getline(cin,deststn);
    Delhi.dijsktraSSSP(sourcestn, dist, prev);
    
    system("echo  \"\e[34m\"");  // blue
    cout<<endl<<"\t\t";
    cout<<"Distance from "<<sourcestn<<" to "<<deststn<<" - "<<dist[deststn]<<" Kms"<<endl;
    cout<<endl<<"\t\tPath: "<<endl;
    Delhi.DijkstraGetShortestPathTo(deststn,prev);
    
               break;
        default: cout<<"INVALID CHOICE";
    }
    cout<<"WANT TO CONTINUE ----> YES OR NO"<<endl;
    cin>>ch;
    }while(ch=="YES"||ch=="yes");
    return 0;
    
}