from sentiment_analysis import compute_tweets

TWEET_FILE=input('Please enter the name of the tweet file: ')
KEYWORD_FILE=input('Please enter the name of the keyword file: ')
print('')
x=compute_tweets(TWEET_FILE,KEYWORD_FILE)

#try is used so if the wrong file is entered then it would simply ask to input a right file
try:
    #int(x[0][1])
    #this is used to compare the regions happiness score and find out which region is the happiest
    if x[0][0]>x[1][0] and x[0][0]>x[2][0] and x[0][0]>x[3][0]:
        print('The Eastern Time Zone is the happiest region')
    elif x[1][0]>x[0][0] and x[1][0]>x[2][0] and x[1][0]>x[3][0]:
        print('The Central Time Zone is the happiest region')
    elif x[2][0]>x[0][0] and x[2][0]>x[1][0] and x[2][0]>x[3][0]:
        print('The Mountain Time Zone is the happiest region')
    elif x[3][0]>x[0][0] and x[3][0]>x[1][0] and x[3][0]>x[2][0]:
       print('The Pacific Time Zone is the happiest region')

    #print statments for the happiness value, keyword tweets & total number of tweets for all regions
    print('')
    print('The happiness value for the EASTERN TIME ZONE is : ', x[0][0])
    print('The total number of key word tweets for the EASTERN TIME ZONE is: ',x[0][1])
    print('The total number of tweets for EASTERN TIME ZONE is: ',x[0][2])
    print('')
    print('The happiness value for the CENTRAL TIME ZONE is : ',x[1][0])
    print('The total number of key word tweets for the CENTRAL TIME ZONE is: ',x[1][1])
    print('The total number of tweets for CENTRAL TIME ZONE is: ',x[1][2])
    print('')
    print('The happiness value for the MOUNTAIN TIME ZONE is : ',x[2][0])
    print('The total number of key word tweets for the MOUNTAIN TIME ZONE is: ',x[2][1])
    print('The total number of tweets for MOUNTAIN TIME ZONE is: ',x[2][2])
    print('')
    print('The happiness value for the PACIFIC TIME ZONE is : ',x[3][0])
    print('The total number of key word tweets for the PACIFIC TIME ZONE is: ',x[3][1])
    print('The total number of tweets for PACIFIC TIME ZONE is: ',x[3][2])
except IndexError:
    print('Please enter a valid file name')
    print('')
    print('The happiness value for the EASTERN TIME ZONE is : ',x)
    print('The total number of key word tweets for the EASTERN TIME ZONE is: ',x)
    print('The total number of tweets for EASTERN TIME ZONE is: ',x)
    print('')
    print('The happiness value for the CENTRAL TIME ZONE is : ',x)
    print('The total number of key word tweets for the CENTRAL TIME ZONE is: ',x)
    print('The total number of tweets for CENTRAL TIME ZONE is: ',x)
    print('')
    print('The happiness value for the MOUNTAIN TIME ZONE is : ',x)
    print('The total number of key word tweets for the MOUNTAIN TIME ZONE is: ',x)
    print('The total number of tweets for MOUNTAIN TIME ZONE is: ',x)
    print('')
    print('The happiness value for the PACIFIC TIME ZONE is : ',x)
    print('The total number of key word tweets for the PACIFIC TIME ZONE is: ',x)
    print('The total number of tweets for PACIFIC TIME ZONE is: ',x)
