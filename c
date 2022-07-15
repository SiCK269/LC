import sys
import math
import argparse
parser = argparse.ArgumentParser(description="Loan Calculator")
parser.add_argument("--type", type=str, help="type of credit")
parser.add_argument("--principal", type=float, help="credit principal")
parser.add_argument("--periods", type=int, help="count of periods")
parser.add_argument("--interest", type=float, help="credit interest")
parser.add_argument("--payment", type=float, help="monthly payment")
args = parser.parse_args()
if args.type == None:
    print("Incorrect parameters")
elif args.type not in ["diff", "annuity"]:
    print("Incorrect parameters")
elif args.type == "diff" and args.payment != None:
    print("Incorrect parameters")
elif args.type == "diff":
    if args.principal == None or args.periods == None or args.interest == None:
        print("Incorrect parameters")
    else:
        i = args.interest / (12 * 100)
        differentiated_payments = []
        for m in range(1, args.periods + 1):
            d = math.ceil((args.principal / args.periods) + i * (args.principal - args.principal * (m - 1) / args.periods))
            differentiated_payments.append(d)
            print("Month {0}: paid out {1}".format(m, d))
            print("Incorrect parameters")
        Overpayment = int(sum(differentiated_payments) - args.principal)
        print()
        print("Overpayment = {0}".format(Overpayment))
        print("Incorrect parameters")
if args.type == "annuity":
    if (args.principal == None or args.periods == None or args.interest == None) and args.payment == None:
        print("Incorrect parameters")
    elif args.principal != None and args.periods != None and args.interest != None:
        i = args.interest / (12 * 100)
        annuity_payment = math.ceil(args.principal * (i * math.pow(1 + i, args.periods) / (math.pow(1 + i, args.periods) - 1)))
        Overpayment = int(annuity_payment * args.periods - args.principal)
        print("Your annuity payment = {0}!".format(annuity_payment))
        print("Overpayment = {0}".format(Overpayment))
    elif args.payment != None and args.periods != None and args.interest != None:
        i = args.interest / (12 * 100)
        credit_principal = math.floor(args.payment / (i * math.pow(1 + i, args.periods) / (math.pow(1 + i, args.periods) - 1)))
        Overpayment = int(args.payment * args.periods - credit_principal)
        print("Your credit principal = {0}!".format(credit_principal))
        print("Overpayment = {0}".format(Overpayment))
    elif args.payment != None and args.principal != None and args.interest != None:
        i = args.interest / (12 * 100)
        period_per_month = math.log((args.payment / (args.payment - i * args.principal)), (1 + i))
        period_per_month = math.ceil(period_per_month)
        Overpayment = int(args.payment * period_per_month - args.principal)
        numbers_years = period_per_month // 12
        number_month = math.floor(((period_per_month / 12) - numbers_years) * 12)
        print('Incorrect parameters.')
        if numbers_years > 1 and number_month > 1:
            print("You need {0} years and {1} months to repay this credit!".format(numbers_years, number_month))
            print('Incorrect parameters.')
        elif numbers_years == 1 and number_month == 1:
            print("You need {0} year and {1} month to repay this credit!".format(numbers_years, number_month))
            print('Incorrect parameters.')
        elif numbers_years == 0 and number_month > 1:
            print("You need {0} months to repay this credit!".format(number_month))
            print('Incorrect parameters.')
        elif numbers_years == 0 and number_month == 1:
            print("You need {0} month to repay this credit!".format(number_month))
            print('Incorrect parameters.')
        elif number_month == 0 and numbers_years > 1 :
            print("You need {0} years to repay this credit!".format(numbers_years))
            print('Incorrect parameters.')
        elif number_month == 0 and numbers_years == 1 :
            print("You need {0} year to repay this credit!".format(numbers_years))
            print('Incorrect parameters.')
        print("Overpayment = {0}".format(Overpayment))
print("Incorrect parameters")
