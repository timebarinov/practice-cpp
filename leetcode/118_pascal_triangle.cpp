// pascal triangle
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res = {{1}};
        while (--n) {
            //задаем размер и заполняем числом (1)
            vector<int> tmp(res.size() + 1, 1);
            //не с начала и не до конца 
            for (int i = 1; i < tmp.size() - 1; ++i) {
                //в данном случае мы берем значение из вектора векторов 
                //и добавляем его во временный вектор
                tmp[i] = res.back()[i - 1] + res.back()[i];
            }        
            res.push_back(tmp); 
        }        
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res = {{1}};
        while (--n) {
            //задаем размер и заполняем числом (1)
            vector<int> tmp(res.size() + 1, 1);
            //не с начала и не до конца
            for(int i = 1; i < tmp.size() -1; ++i){
                //а тут мы проходим по временному вектору
                //и при каждой итерации меняем значения все кроме 1 и последнего
                for(int j = i; j > 0; --j) {
                    tmp[j] = tmp[j] + tmp[j-1];
                }
            }
            res.push_back(tmp); 
        }        
        return res;
    }
};
