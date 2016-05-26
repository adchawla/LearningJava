package x03_Generics;

public class Account<AccountType> {
	
	@Override
	public String toString() {
		return "Account [mAccountNumber=" + mAccountNumber + ", mBalance="
				+ mBalance + "]";
	}

	private AccountType mAccountNumber;
	private float mBalance;
	
	public Account(AccountType accountNumber) {
		mAccountNumber = accountNumber;
	}

	public float getBalance() {
		return mBalance;
	}

	public void setBalance(float mBalance) {
		this.mBalance = mBalance;
	}

	/**
	 * @return the mAccountNumber
	 */
	public AccountType getAccountNumber() {
		return mAccountNumber;
	}
	
}
