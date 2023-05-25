#include <iostream>
#include <vector>

int r,c,k;
std::vector<std::vector<char>> basketballCourt;

bool isAvaliable(int i, int j, int type){
    for (int l = 1; l < k; l++){
        if (type == 1 && basketballCourt[i][j+l] == '#') {
            return false;
        }
        if (type == 2 && basketballCourt[i+l][j] == '#') {
            return false;
        }
    }
    return true;
}

int searchStart(){
    int count = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (basketballCourt[i][j] == '.'){
                if (j + k - 1 < c) {
                    if (isAvaliable(i,j,1)) count++;
                }    
                if (i + k - 1 < r) {
                    if (isAvaliable(i,j,2)) count++;
                }
            }
        }
    }
    return count;
}

int main(){
    std::cin >> r >> c >> k;
    basketballCourt.resize(r, std::vector<char>(c));

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            std::cin >> basketballCourt[i][j];
        }
    }

    if(k == 1)
	{   
        int count = 0;
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				if(basketballCourt[i][j]=='.')
					count++;
			}
		}
		std::cout << count;
		return 0;
	}else{
        int count = searchStart();
        std::cout << count;
    }

    return 0;
}


