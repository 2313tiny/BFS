#include "graph.hpp" 

void BFS(Graph & graph,Vertex & start)
{
	std::vector<Vertex> likeQueue;	
	std::vector<Vertex>::const_iterator likeQueueIt;	
	std::vector<Vertex>::const_iterator likeQueueCheckedIt;
	
	std::vector<Vertex>::const_iterator zenitIt;
	std::list<Edge>::iterator depositIt;

	likeQueue.push_back(start);
	likeQueueCheckedIt = likeQueue.begin();		

	std::vector<Vertex> traverse;
	std::vector<Vertex>::iterator traverseIt;

	Vertex gagat;

	//first step .... DONE
	for (zenitIt = graph.zenit.begin(); zenitIt != graph.zenit.end(); ++zenitIt){
		int node = likeQueueCheckedIt->m_node -1  ;
		for (depositIt = graph.deposit[node].begin(); 
			depositIt != graph.deposit[node].end(); ++depositIt){
			if (zenitIt->m_node == depositIt->m_source.m_node){
					if ( zenitIt->m_node != depositIt->m_target.m_node){
						likeQueue.push_back( depositIt-> m_target);
					}
			}
			gagat = Vertex(depositIt->m_source);
		}
	}
	  traverse.push_back(gagat); 

		
	for (int i = 0; i < GRAPH_ORDER-1; ++i){	
		
		traverseIt = traverse.begin();
		likeQueueCheckedIt = likeQueue.begin();
		
		for (int p = 0; p <= i; ++p){
			++likeQueueCheckedIt;
		}
		
		int node = likeQueueCheckedIt->m_node -1  ;
		for (depositIt = graph.deposit[node].begin(); 
			depositIt != graph.deposit[node].end(); ++depositIt){
			if (likeQueueCheckedIt->m_node == depositIt->m_source.m_node){
			
				int count = 0; //if node according do not need to add vertex to Queue
				for (likeQueueIt = likeQueue.begin(); likeQueueIt != likeQueue.end(); ++likeQueueIt){		
					if (likeQueueIt->m_node == depositIt->m_target.m_node){
						count++;
					} 
				}
					if(0 == count ){
						likeQueue.push_back(depositIt->m_target);
					}			
			}
			gagat = Vertex(depositIt->m_source);

		}
	  traverse.push_back(gagat); 
	}

	std::cout << YELLOW << "\nBreadth first search for "
 		  << "traversing graph data structure\n" << RESET;
		for (auto x : traverse){
		std::cout << x.m_node  << " " << x.m_name << " - ";
	}

}
