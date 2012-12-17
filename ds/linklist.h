class CKLinkList{
	private:
		struct node {
			int x;
			int y;
			int z;
			node *link;
		} *p;

		int count_i;

	public:
		CKLinkList();
		void append(int);
		void insert_after(int,int);
		void insert_first(int);

		void display(void);
		void display_line(void);
		int length(void);
		void del(int);
		~CKLinkList();
};
