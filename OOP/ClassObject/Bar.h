#pragma once
class Bar {

private:
    int bar=100;

public:
    void setBarValue(int pBar);
    void setBarValueUsingThis(int bar);
    ~Bar();
    Bar();

};

