#ifndef OBSERVER_H
#define OBSERVER_H

class Observable;

class Observer
{
public:
	Observer(Observable* a_Observable);
	virtual ~Observer(void);

	virtual void UpdateState() = 0;

protected:
	Observable* m_pObservable;
};

#endif