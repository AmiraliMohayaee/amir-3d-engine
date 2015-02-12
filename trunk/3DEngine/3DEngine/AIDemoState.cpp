#include "Game.h"
#include "MyGL.h"
#include "SoundManager.h"
#include "Car.h"
#include "FontManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <assert.h>
#include "Billboard.h"
#include "Light.h"
#include "Material.h"
#include "Timer.h"
#include "TextureManager.h"
#include "ObjMesh.h"
#include "Player.h"
#include "CollisionMesh.h"
#include "Enemy.h"
#include "Room.h"
#include "WinState.h"
#include "LossState.h"

#include "AIDemoState.h"
#include "Graph.h"
#include "GraphNode.h"
#include "GraphEdge.h"
#include "DepthFirstSearch.h"
#include "DepthFirstSearchTest.h"
#include "BreadthFirstSearch.h"
#include "Dijkstra.h"
#include "AStar.h"


// A set of global variables that were previously used
//ObjMesh mesh;
//Player player;
//CollisionMesh coll;
//Enemy enemy;

namespace Engine
{
	AIDemoState::AIDemoState()
	{
		GLuint texId = -1;
	}


	void AIDemoState::OnActivated()
	{
		GameState::OnActivated();

		ObjMesh obj;

		//GraphNode node0(0);
		//GraphNode node1(1);
		//typedef std::vector<GraphNode> Nodes;
		
		text.Load("assets/fonts/Doom32Bit.png", 16, 16);

		// call a new algorithm
		// set a trail for each

		unsigned int n = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int i =0; i < 5; i++)
			{
				GraphNode node(n);
				node.SetPos(Vec3f(i, 0, j));
				dfgraph.AddNode(node);

				if (i > 0)
				{
					dfgraph.AddEdge((GraphEdge(n, n - 1, 7.0f)));
					dfgraph.AddEdge((GraphEdge(n - 1, n, 7.0f)));
				}
				if (j > 0)
				{
					dfgraph.AddEdge((GraphEdge(n, n - 5, 7.0f)));
					dfgraph.AddEdge((GraphEdge(n - 5, n, 7.0f)));
				}
				n++;
			}
		}

		DepthFirstSearch df;
		Trail pathdf;
		df.Dfs(dfgraph, 0, 7, pathdf);
		dfgraph.SetTrail(pathdf);



		unsigned int k = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				GraphNode node(k);
				node.SetPos(Vec3f(i, 0, j));
				bfgraph.AddNode(node);

				if (i > 0)
				{
					bfgraph.AddEdge((GraphEdge(k, k - 1, 7.0f)));
					bfgraph.AddEdge((GraphEdge(k - 1, k, 7.0f)));
				}
				if (j > 0)
				{
					bfgraph.AddEdge((GraphEdge(k, k - 5, 7.0f)));
					bfgraph.AddEdge((GraphEdge(k - 5, k, 7.0f)));
				}
				k++;
			}
		}

		BreadthFirstSearch bfs;
		Trail pathbf;
		bfs.Bfs(bfgraph, 0, 7, pathbf);
		bfgraph.SetTrail(pathbf);



		unsigned int l = 0;
		for (int j = 0; j < 5; j++)
		{
			for (int i =0; i < 5; i++)
			{
				GraphNode node(l);
				node.SetPos(Vec3f(i, 0, j));
				dgraph.AddNode(node);

				if (i > 0)
				{
					dgraph.AddEdge((GraphEdge(l, l - 1, 7.0f)));
					dgraph.AddEdge((GraphEdge(l - 1, l, 7.0f)));
				}
				if (j > 0)
				{
					dgraph.AddEdge((GraphEdge(l, l - 5, 7.0f)));
					dgraph.AddEdge((GraphEdge(l - 5, l, 7.0f)));
				}
				l++;
			}
		}

		Dijkstra d;
		Trail pathd;
		d.DijkstraSerach(dgraph, 0, 7, pathd);
		dgraph.SetTrail(pathd);


		unsigned int m = 0;
		for (unsigned int j = 0; j < 5; j++)
		{
			for (unsigned int i =0; i < 5; i++)
			{
				GraphNode node(m);
				node.SetPos(Vec3f(i, 0, j));
				aSgraph.AddNode(node);

				if (i > 0)
				{
					aSgraph.AddEdge((GraphEdge(m, m - 1, 7.0f)));
					aSgraph.AddEdge((GraphEdge(m - 1, m, 7.0f)));
				}
				if (j > 0)
				{
					aSgraph.AddEdge((GraphEdge(m, m - 5, 7.0f)));
					aSgraph.AddEdge((GraphEdge(m - 5, m, 7.0f)));
				}
				m++;
			}
		}

		AStar a;
		Trail patha;
		a.AStarSearch(aSgraph, 0, 7, patha);
		aSgraph.SetTrail(patha);
	}

	void AIDemoState::OnDeActivated()
	{
		GameState::OnDeActivated();
	}


	void AIDemoState::Draw()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHTING);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_BLEND);
		glEnable(GL_CULL_FACE);

		//ObjMesh obj;
		//obj.Load("Assets/Levels/AI/scene1.obj");
		//obj.Draw();

		//////////////////////////////
		// Drawing Nodes
		//////////////////////////////
		//std::cout << "AI test:\n\n";

		//graph.AddNode(node0);
		//graph.AddNode(node1);

		//for (int i =0; i > 40; i++)
		//{

		//}

		//graph.AddEdge((GraphEdge(0, 1, 7.0f)));
		//graph.AddEdge((GraphEdge(1, 0, 8.0f)));
		

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glCullFace(GL_BACK);


		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(80.0, 1.0, 0.5, 1000.0);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(
			0, 6, 8.0, // camera pos
			0, 3, 1,  // coordinations of where we're looking at
			0, 0.2, 0);// Rotation


					
		//// Drawing Dijkstra
		glViewport(0, 300, 400, 300);
		glPushMatrix();
		dgraph.Draw();
		glPopMatrix();
		

		// Drawing A*
		glViewport(400, 300, 400, 300);
		glPushMatrix();
		//text.Draw("A*", 0, 0, 10);
		aSgraph.Draw();
		glPopMatrix();

		//// Drawing Deathpth first search
		glViewport(0, 0, 400, 300);
		glPushMatrix();
		dfgraph.Draw();
		glPopMatrix();

		//// Drawing Breadth first search
		glViewport(400, 0, 400, 300);
		glPushMatrix();
		bfgraph.Draw();
		glPopMatrix();


		// re-enabling lighting
		glEnable(GL_LIGHTING);
	}

	void Engine::AIDemoState::Update()
	{
		TheGame::Instance()->UpdateGameObjects();
	}

	void Engine::AIDemoState::OnKeyboardEvent(const SDL_KeyboardEvent& k)
	{
		if (k.keysym.sym == SDLK_ESCAPE &&  k.state == SDL_PRESSED)
		{
			SDL_Quit();
			exit(0);
		}
	
		/*if (k.keysym.sym == SDLK_SPACE &&  k.state == SDL_PRESSED)
		{
			TheSoundManager::Instance()->PlayMusic("DoomMusic/e4m4.mid");
		}*/
	}
}