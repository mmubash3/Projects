#list of all fixed values
EGG=0.99
BACON=0.49
SAUSAGE=1.49
HASHBROWN=1.19
TOAST=0.79
COFFEE=1.09
TEA=0.89

SMALLBREAKFAST=EGG+ HASHBROWN+2*(TOAST)+2*(BACON)+SAUSAGE
REGULARBREAKFAST=2*(EGG)+HASHBROWN+2*(TOAST)+4*(BACON)+2*(SAUSAGE)
BIGBREAKFAST=3*(EGG)+2*(HASHBROWN)+4*(TOAST)+6*(BACON)+3*(SAUSAGE)

#made a list so it's easier to do conditional statement
PRODUCTS= ['EGG','BACON','SAUSAGE','HASHBROWN','TOAST','COFFEE','TEA','SMALLBREAKFAST','REGULARBREAKFAST','BIGBREAKFAST']

print("Welcome to Good Morning America")


item= input("Enter item (q to terminate): small breakfast, regular breakfast, big breakfast, egg, bacon, sausage, hash brown, toast, coffee, tea:")
pretax_bill= []
#.strip was used so any tab spaces could be removed, and replace was used in order to take out the space inbetween regular breakfast, as i've saved the key term as REGULARBREAKFAST, and the upper function is so everything would get capitilized
item=item.upper().replace(" ",'').strip()

while item!='Q':
  if (item in PRODUCTS):
    if item == 'SMALLBREAKFAST':
      ITEM= SMALLBREAKFAST
    elif item == 'REGULARBREAKFAST':
      ITEM= REGULARBREAKFAST
    elif item == 'BIGBREAKFAST':
      ITEM= BIGBREAKFAST
    elif item == 'EGG':
      ITEM= EGG
    elif item == 'BACON':
      ITEM= BACON
    elif item == 'SAUSAGE':
      ITEM= SAUSAGE
    elif item == 'HASHBROWN':
      ITEM= HASHBROWN
    elif item == "TOAST":
      ITEM= TOAST
    elif item == 'COFFEE':
      ITEM= COFFEE
    elif item == 'TEA':
      ITEM = TEA
    quantity= input("How many do you want? ")
    if quantity.isnumeric():
      quantity=int(quantity)
      cost_of_item= quantity * ITEM
      pretax_bill.append(cost_of_item)
    else:
      print('Please enter a numeric value')
      quantity= int(input("How many do you want? "))
    item= input("Enter item (q to terminate): small breakfast, regular breakfast, big breakfast, egg, bacon, sausage, hash brown, toast, coffee, tea:")
    item=item.upper().replace(" ",'').strip().replace(' ','')
  #this else statement was so that if wrong input would be put in they system would keeo asking for the correct input
  else:
    print('Please enter a valid item from the menu')
    item= input("Enter item (q to terminate): small breakfast, regular breakfast, big breakfast, egg, bacon, sausage, hash brown, toast, coffee, tea:")
    item=item.upper().replace(" ",'').strip()

    #access the dictionary and mention the order and if they are sure of the order and if they want to edit it
    #find out how to print from dictionaries & how to amend dictionaries
    #show the total price post tax and pre tax

pretax_bill= sum(pretax_bill)
tax= 0.13*pretax_bill
Total=pretax_bill+tax


print('Cost: $',round(pretax_bill,2)  )
print('Tax: $', round(tax,2))
print('Total: $', round(Total,2))
