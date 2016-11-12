template<class K, class V>
class KVStore{
private:
    long tailIdx = -1;
    unordered_map<K, V> hashmap;
public:
    void put(K key, V val){
        hashmap.insert({key, val});
        tailIdx++;
    }

    long getTailIdx(){
        return tailIdx;
    } 

    bool contains(K key){
        return hashmap.count(key) > 0;
    }

    V& get(K key){
        return hashmap[key];
    }
};

struct URLItem{
    int visited;
    string origin;
};

class URLShort{
private:
    KVStore<long, URLItem> dataStore;   
    string encode62(long num){
        return to_string(num);
    }
    long decode62(string str){
        return stoi(str);
    }
public:
    string shorten(string url){
        long key = dataStore.getTailIdx() + 1;
        dataStore.put(key, {0, url});
        return encode62(key);
    }

    string restore(string shortenUrl){
        long key = decode62(shortenUrl);
        if (!dataStore.contains(key))
            return "error";
        auto& val = dataStore.get(key);
        val.visited++;
        return val.origin;
    }
};
