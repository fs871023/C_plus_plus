class Diamond
{
private:
    int *side_length;
    char *border;
    char *fill_char;

public:
    Diamond(int len,char bdr='#',char fchar='*');//constructor
    ~Diamond();//destructor
    int GetSize (void) const;
    int Perimeter(void) const;
    double Area(void) const;
    void Grow(void);
    void Shrink(void);
    void SetBorder(char);
    void SetFill(char);
    void Draw(void) const;
    void Summary(void);

};
