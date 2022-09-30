public class hw1 {
	    public static void main(String[] argv)
	    {
	        int i, j, k;
	        char[] chars= {0};
	        int [] _count;
	        for(i=0;i<argv.length;i++)
	        {
	        	for(j=0;j<argv[i].length;j++)
	        	{
	        		for(k=0;k<100;k++)
	        		{
		        		if(argv[i][j]==chars[k])
		        		{
		        			_count[k]++;
		        			break;
		        		}
		        		if(chars[k]==0)
		        		{
		        			chars[k]=argv[i][j];
		        			break;
		        		}
	        		}
	        		if(argv[i][j]=='\0')
	        			break;
	        	}
	        }

	        for(i=0;i<chars.length;i++)
	        {
	            System.out.println(chars[i]+"-"+_count[i]);)
	        }
	    }

}
