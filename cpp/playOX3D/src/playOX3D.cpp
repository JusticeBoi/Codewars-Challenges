#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
std::string playOX3D(const std::vector<std::vector<int>> &moves);
std::pair <bool,int> hasWinned(const std::vector<std::vector<int>>& o_or_x);

int main()
{

	const std::vector<std::vector<int>> a = {{0,1,1},
            {0,0,0},   // X
            {0,2,2},
            {1,1,1},   // X
            {1,2,2},
            {2,2,2},   // X
            {2,1,2},
            {3,3,3},   // X
            {0,2,1}};
	const std::vector<std::vector<int>> b = {{0,2,1},   // O
            {0,2,2},
            {1,2,1},   // O
            {1,2,2},
            {2,2,1},   // O
            {2,2,2},
            {3,2,1},   //0
			{0,0,0},
			{3,2,2}};

	const std::vector<std::vector<int>> c ={{0,0,0},
	                               {1,1,1},
	                               {2,2,2},
	                               {3,3,3}};

	std::cout <<playOX3D(b) <<std::endl;

	return 0;
}
void print(const std::vector<std::vector<int>> &moves)
{

}
std::pair <bool,int> hasWinned(const std::vector<std::vector<int>>& o_or_x)
		{

	std::vector<int> zero = {0,0,0};
	std::vector<int> one = {1,1,1};
	std::vector<int> two = {2,2,2};
	std::vector<int> three = {3,3,3};

	std::vector<int> space_diag_10 = {3,3,0};
	std::vector<int> space_diag_11= {2,2,1};
	std::vector<int> space_diag_12 = {1,1,2};
	std::vector<int> space_diag_13 = {0,0,3};

	std::vector<int> space_diag_20 = {3,0,3};
	std::vector<int> space_diag_21= {2,1,2};
	std::vector<int> space_diag_22 = {1,2,1};
	std::vector<int> space_diag_23 = {0,3,0};

	std::vector<int> space_diag_30 = {0,3,3};
	std::vector<int> space_diag_31= {1,2,2};
	std::vector<int> space_diag_32 = {2,1,1};
	std::vector<int> space_diag_33 = {3,0,0};

//		std::sort(o_or_x.begin(),o_or_x.end());
		if(o_or_x.size() < 4) return std::make_pair(false,0);
		else if ( std::binary_search(o_or_x.begin(),o_or_x.end(),zero) && std::binary_search(o_or_x.begin(),o_or_x.end(),one)
				&& std::binary_search(o_or_x.begin(),o_or_x.end(),two) && std::binary_search(o_or_x.begin(),o_or_x.end(),three))
		{
			std::cout <<"3d diagonal win!" <<std::endl;
					return std::make_pair(true,o_or_x.size());
		}
		else if ( std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_10) && std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_11)
						&& std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_12) && std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_13))
				{
					std::cout <<"3d diagonal win!" <<std::endl;
							return std::make_pair(true,o_or_x.size());
				}
		else if ( std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_20) && std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_21)
						&& std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_22) && std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_23))
				{
					std::cout <<"3d diagonal win!" <<std::endl;
							return std::make_pair(true,o_or_x.size());
				}
		else if ( std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_30) && std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_31)
						&& std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_32) && std::binary_search(o_or_x.begin(),o_or_x.end(),space_diag_33))
				{
					std::cout <<"3d diagonal win!" <<std::endl;
							return std::make_pair(true,o_or_x.size());
				}
		else
		{
//			std::vector<std::vector<int>> xy_equal;
//			std::vector<std::vector<int>> xz_equal;
//			std::vector<std::vector<int>> yz_equal;
			int xy_counter=0;
			int xz_counter=0;
			int yz_counter=0;
			for(auto& outer_vec : o_or_x)
			{
				for(auto& inner_vec : o_or_x)
				{
					if(inner_vec[0] == outer_vec[0] && inner_vec[1] == outer_vec[1] && inner_vec != outer_vec) ++xy_counter;
					if(inner_vec[0] == outer_vec[0] && inner_vec[2] == outer_vec[2] && inner_vec != outer_vec) ++xz_counter;
					if(inner_vec[1] == outer_vec[1] && inner_vec[2] == outer_vec[2] && inner_vec != outer_vec) ++yz_counter;
				}
//				 std::for_each(o_or_x.begin(),o_or_x.end(),[&yz_equal,&xz_equal,&xy_equal,&o_or_x,&it_vec](const std::vector<int>& vec)
//						{
//							if((it_vec[0]==vec[0] && it_vec[1]==vec[1]) && vec !=it_vec) xy_equal.push_back(vec);
//							else if((it_vec[1]==vec[1] && it_vec[2]==vec[2]) && vec !=it_vec ) yz_equal.push_back(vec);
//							else if((it_vec[0]==vec[0] && it_vec[2]==vec[2]) && vec !=it_vec ) xz_equal.push_back(vec);
//						});
				if ( xy_counter == 3 || xz_counter == 3 || yz_counter == 3)
					{
					for(auto& v : o_or_x)
									{
										std::cout <<"[ ";
										for(auto& n : v )
										{
											std::cout << n<<" ,";
										}
										std::cout <<" ]"<<std::endl;
									}
						return std::make_pair(true,o_or_x.size());
					}
				xy_counter = 0;
				xz_counter = 0;
				yz_counter = 0;
			}
//			std::sort(yz_equal.begin(),yz_equal.end());
//			std::sort(xz_equal.begin(),xz_equal.end());
//			std::sort(xy_equal.begin(),xy_equal.end());
//
//			auto last_yz = std::unique(yz_equal.begin(),yz_equal.end());
//			auto last_xz = std::unique(xz_equal.begin(),xz_equal.end());
//			auto last_xy = std::unique(xy_equal.begin(),xy_equal.end());
//
//			yz_equal.erase(last_yz, yz_equal.end());
//			xz_equal.erase(last_xz, xz_equal.end());
//			xy_equal.erase(last_xy, xy_equal.end());
//
//			std::cout << yz_equal.size()<<std::endl;
//			std::cout << xz_equal.size()<<std::endl;
//			std::cout << xy_equal.size()<<std::endl;
//
//			if(xy_equal.size()==4)
//				{
//				for(auto& v : xy_equal)
//				{
//					std::cout <<"[ ";
//					for(auto& n : v )
//					{
//						std::cout << n<<" ,";
//					}
//					std::cout <<" ]"<<std::endl;
//				}
//					return std::make_pair(true,o_or_x.size());
//				}
//			else if (xz_equal.size()==4)
//			{
//				for(auto& v : xz_equal)
//				{
//					std::cout <<"[ ";
//					for(auto& n : v )
//					{
//						std::cout << n<<" ,";
//					}
//					std::cout <<" ]"<<std::endl;
//				}
//				return std::make_pair(true,o_or_x.size());
//			}
//			else if (yz_equal.size()==4)
//			{
//				for(auto& v : yz_equal)
//				{
//					std::cout <<"[ ";
//					for(auto& n : v )
//					{
//						std::cout << n<<" ,";
//					}
//					std::cout <<" ]"<<std::endl;
//				}
//				return std::make_pair(true,o_or_x.size());
//			}

		}

			return std::make_pair(false,0);
		}
std::string playOX3D(const std::vector<std::vector<int>> &moves)
{
	if(moves.size() < 7) return "No winner";
	std::vector<std::vector<int>> o ;
	std::vector<std::vector<int>> x ;
	std::string ans = std::string();
	for (std::size_t i = 0; i < moves.size() ; i++)
	{
		if ( !(i % 2) )
		{
			o.push_back(moves[i]);
			auto win_O = hasWinned(o);
			if(win_O.first)
				{
					ans = "O wins after "+ std::to_string(win_O.second + x.size()) + " moves";
//					std::cout << ans <<std::endl;
					return ans;
				}
		}

		else
		{
			x.push_back(moves[i]);
			auto win_x = hasWinned(x);
			if(win_x.first)
			{
				ans = "X wins after "+ std::to_string(win_x.second + o.size()) + " moves";
//				std::cout << ans <<std::endl;
				return ans;
			}
		}
	}
	return "No winner";
}
