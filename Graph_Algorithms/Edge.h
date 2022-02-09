template <typename T>
class Edge {
public:
    int src, des;
    T wgt;
    Edge<T> (int source, int destination, int weight)
    {
        this->src = source;
        this->des = destination;
        this->wgt = weight;
    }
    Edge<T> (void) {}
    ~Edge<T> (void) {}
    int source(void) const
    {
        return this->src;
    }
    int destination(void) const
    {
        return this->destination;
    }
    T weight(void) const
    {
        return this->wgt;
    }
};