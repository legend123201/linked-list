void Insert(NODEPTR &pavltree, int x, int a)
{
   NODEPTR fp, p, q,
           fya, ya, s;           	
   int imbal;           	
   fp = NULL;   p = pavltree;
   fya = NULL;   ya = p;
   while(p != NULL)
   {
      if (x == p->key)  
         return;
      if (x < p->key)
	 	q = p->left;
      else      	
	  	q = p->right;
      if(q != NULL)
         if(q->bf != 0) 
         { fya = p;
            ya = q;
         }
      fp = p;
      p = q;
   }
q = new node;
q->key =x;  q->info = a;  q->bf = 0;
q->left = NULL;  q->right = NULL;
    if(x < fp->key)
      fp->left = q;
   else      
   	fp->right = q;
   
   if(x < ya->key)
      p = ya->left;
   else
      p = ya->right;
   s = p;     // s la con nut ya
   while(p != q)
   { if(x < p->key)
      { p->bf = 1;
         p = p->left;
      }
      else
      {  	p->bf = -1;
	 	p = p->right;
      }
   }
   // xac dinh huong lech
   if(x < ya->key)
      imbal = 1;
   else
      imbal = -1;

   if(ya->bf == 0)
   { ya->bf = imbal;
      return;
   }
   if(ya->bf != imbal)
   { ya->bf = 0;
      return;
   }

   if(s->bf == imbal)   
   { if(imbal == 1)    
         p = Rotate_Right(ya);
      else              
         p = Rotate_Left(ya);
      ya->bf = 0;
      s->bf = 0;
   }
   else                 
   { if(imbal == 1)    
      { ya->left = Rotate_Left(s);
         p = Rotate_Right(ya);
      }
      else              
      { 	ya->right = Rotate_Right(s);
	 	p = Rotate_Left(ya);
      }
      if(p->bf == 0)   
      { ya->bf = 0;
         s->bf = 0;
      }
      else
         if(p->bf == imbal)
         { ya->bf = -imbal;
            s->bf = 0;
         }
         else
         { ya->bf = 0;
            s->bf = imbal;
         }
      p->bf = 0;
   }
   if(fya == NULL)
      pavltree = p;
   else
      if(ya == fya->right)
         fya->right = p;
      else
         fya->left = p;
}

void Create_AVLTree(NODEPTR &root)
{ int khoa, noidung;
  char so[10];
  NODEPTR p;
  do
  { printf("Nhap khoa :");    gets(so) ;
    khoa = atoi(so);
    if (khoa !=0)
    { printf("Nhap noi dung :");
      gets(so) ;
      noidung = atoi(so);
      if (root==NULL)
      { 	p = New_Node();
p->key = khoa;	p->info = noidung;   p->bf   = 0 ;   
p->left = NULL;   p->right = NULL;
root =p;
       }
      else Insert(root,khoa,noidung);
      }
    } while (khoa!=0);	
}

