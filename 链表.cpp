#include <iostream>
    using namespace std;
    struct test
    {
        int number;
        float socre;
        test *next;
    };
    test *head;//����һ��ȫ�ֵ��������������ָ��

    test *create()
    {
        test *ls;//�ڵ�ָ��
        test *le;//��βָ��
        ls = new test;//��lsָ��̬���ٵĶ��ڴ��ַ
        cin>>ls->number>>ls->socre;
        head=NULL;//�����ʱ���Ȳ�����headָ��ָ���κε�ַ,��Ϊ��֪���Ƿ�һ����������null��������
        le=ls;//����βָ�����óɸոն�̬���ٵĶ��ڴ��ַ,���ڵ�������le->next,Ҳ������һ���ڵ��λ��
        while(ls->number!=0)//����ѭ������Ϊls->number��ֵ����null,����ѭ����ӽڵ�
        {
            if(head==NULL)//�ж��Ƿ��ǵ�һ�ν���ѭ��
            {
                head=ls;//����ǵ�һ�ν���ѭ��,��ô���������������ָ��ָ���һ�ζ�̬���ٵĶ��ڴ��ַ
            }
            else
            {
                le->next=ls;//������ǵ�һ�ν�����ô�Ͱ���һ�ε���βָ���le->nextָ����һ��ѭ������ǰ��̬�����Ķ��ڴ��ַ
            }
            le=ls;//������βָ��Ϊ��ǰѭ���еĽڵ�ָ��,������һ�ν���ѭ����ʱ�����һ�εĽڵ��nextָ����һ��ѭ������ǰ��̬�����Ķ��ڴ��ַ
            ls=new test;//Ϊ��һ���ڵ��ڶ��ڴ��ж�̬���ٿռ�
            cin>>ls->number>>ls->socre;
        }
        le->next=NULL;//����βָ���next����Ϊ��,��Ϊ�������ѭ������Ҫ������,����Ϊ�ղ��ܹ���ѭ���������ʱ��������ѭ��
        delete ls;//��������ʱ�����һ����̬���ٵ��ڴ�����Ч��,���Ա��������
        return head;//��������ָ��
    }
    void showl(test *head)
    {
        cout<<"����ָ��:"<<head<<endl;
        while(head)//���ڴ�ָ��ΪnullΪ����ѭ����ʾ��ǰ���������
        {
            cout<<head->number<<"|"<<head->socre<<endl;
            head=head->next;
        }
    }
    void deletel(test *&head,int number)//���������������test *head,�������ȫ��ͬ��,head����˸��ƶ�����ԭ�����ϲ�����,�ر�ע��,�ܶ����϶���������
    {
        test *point;//�ж������Ƿ�Ϊ��
        if(head==NULL)
        {
            cout<<"����Ϊ��,���ܽ���ɾ������!";
            return;
        }
        if(head->number==number)//��ɾ���Ľڵ��Ƿ�Ϊ�׽ڵ�
        {
            point=head;
            cout<<"ɾ�����������һ���ڵ�λ��!";
            head=head->next;//������������ָ��
            delete point;
            return;
        }
        test *fp=head;//��������ָ��
        for(test *&mp=head;mp->next;mp=mp->next)
        {
            if(mp->next->number==number)
            {
                point=mp->next;
                mp->next=point->next;
                delete point;
                head=fp;//����head�Ĳ����ƶ���ʧ��head,�ѽ���ѭ��ǰ��headָ��ָ�!
                return;
            }
        }
    }
    void main()
    {
        head=create();//���ô���
        showl(head);
        int dp;
        cin>>dp;
        deletel(head,dp);//����ɾ��
        showl(head);
        cin.get();
        cin.get();
    }