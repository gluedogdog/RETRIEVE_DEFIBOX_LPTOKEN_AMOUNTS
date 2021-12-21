

    //TABLE
    struct [[eosio::table]] account {
            asset    balance;

            uint64_t primary_key()const { return balance.symbol.code().raw(); }
    };
     typedef eosio::multi_index< "accounts"_n, account > accounts;


    //FUNCTION TO FIND USER AMOUT OF GLUEDOG LP TOKEN INSIDE DEFIBOX TABLE
    asset get_asset_amount(name user, asset token )//user and glue dog LP tokan, amount doesnt matter just put something there to quickly have the symbol
    {

        symbol lpsym = token.symbol;
        asset lpbalance;
        accounts to_acnts( name{"lptoken.defi"}, user.value );
        for (auto it = to_acnts.begin(); it != to_acnts.end(); it++){
            if((it->balance).symbol == lpsym){
                  lpbalance = it->balance;
                  break;
            }
        }
        return lpbalance;

    }


    

 
