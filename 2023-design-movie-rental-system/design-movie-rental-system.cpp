class MovieRentingSystem {
public:

    set<vector<int>> unrentedMoviesDetails; // {price, shop, movie}
    set<vector<int>> rentedMoviesDetails;   // {price, shop, movie}
    map<pair<int,int>, int> moviesPrice;    // {shop, movie} -> price
    map<int, set<pair<int,int>>> movieDetailsUnrented; // movie -> set<{price, shop}>

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &moviesDetails: entries){
            int shop = moviesDetails[0], movie = moviesDetails[1], price = moviesDetails[2];
            unrentedMoviesDetails.insert({price, shop, movie});
            moviesPrice[{shop, movie}] = price;
            movieDetailsUnrented[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> shops;
        for(auto &price_shop: movieDetailsUnrented[movie]){
            shops.push_back(price_shop.second);
            if(shops.size() == 5) break;
        }
        return shops;
    }
    
    void rent(int shop, int movie) {
        int price = moviesPrice[{shop, movie}];
        vector<int> movieDetails = {price, shop, movie};
        unrentedMoviesDetails.erase(movieDetails);
        rentedMoviesDetails.insert(movieDetails);
        movieDetailsUnrented[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        int price = moviesPrice[{shop, movie}];
        vector<int> movieDetails = {price, shop, movie};
        rentedMoviesDetails.erase(movieDetails);
        unrentedMoviesDetails.insert(movieDetails);
        movieDetailsUnrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for(auto &moviesDetails: rentedMoviesDetails){
            res.push_back({moviesDetails[1], moviesDetails[2]});
            if(res.size() == 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */