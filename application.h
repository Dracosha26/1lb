#ifndef APPLICATION_H
#define APPLICATION_H


class Application
{
public:
    Application(int argc, char *argv[]);
    void menu(int &ch);
    void exec();
};

#endif // APPLICATION_H
