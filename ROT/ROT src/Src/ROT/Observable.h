#ifndef OBSERVABLE_H
#define OBSERVABLE_H

class Observer;

// supports "pull" model for notifying observers
class Observable
{
public:
	Observable(void);
	virtual ~Observable(void);

	void AddObserver(Observer* a_Observer);
	void RemoveObserver(Observer* a_Observer);

	void NotifyObservers();

	void StateSetChanged();

protected:
	bool m_Changed;
	std::list< Observer* > m_pObserverlist;
};

#endif